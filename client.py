"""
Example for using the RFM9x Radio with Raspberry Pi.

Learn Guide: https://learn.adafruit.com/lora-and-lorawan-for-raspberry-pi
Author: Brent Rubell for Adafruit Industries
"""

# Import Python System Libraries
import time
import codecs
import logging
import os

from dotenv import load_dotenv
load_dotenv()

# Import RFM9x
import adafruit_rfm9x
# Import the SSD1306 module.
import adafruit_ssd1306
# Import Blinka Libraries
import board
import busio
from digitalio import DigitalInOut, Direction, Pull

# Import Pimoroni Hat Libs
import automationhat

# Import Python Imaging Library
from PIL import Image, ImageDraw, ImageFont

# Import stuff for hashing
# from Crypto.Hash.HMAC import new
import hmac
import hashlib
# from Crypto.Hash.SHA256 import SHA256Hash
from Crypto.Random import get_random_bytes

# Import Message Definition
import messages_pb2

#################### Set up env shit ############################
ENV = os.getenv('QLIKR_ENV')
ID = os.getenv('QLIKR_ID')
SECRET = bytes(os.getenv('QLIKR_SECRET'), 'utf-8')

#꧁
PREAMBLE = bytes(os.getenv('QLIKR_PREAMBLE'), "utf-8")
CHANNEL = int(os.getenv('QLIKR_CHANNEL'))
ALLOWABLE_TIME_ERROR = int(os.getenv('QLIKR_ALLOWED_TIME_ERROR'))

ENV_REMOTE = 'remote'
ENV_BASE = 'server'


def is_remote():
    return ENV == ENV_REMOTE


def is_base():
    return ENV == ENV_BASE


RELAY_TIME = .1

last_sent_mac = None
#################################################################

logger = logging.getLogger("qlikr.{}".format(ENV))

__all__ = ['logger', 'run_client']

file_log_handler = logging.FileHandler('/home/pi/log/qlikr.log')
logger.addHandler(file_log_handler)

stderr_log_handler = logging.StreamHandler()
logger.addHandler(stderr_log_handler)

# nice output format
formatter = logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s')
file_log_handler.setFormatter(formatter)
stderr_log_handler.setFormatter(formatter)
logger.setLevel('DEBUG')

logger.info("Initializing Hardware")

if is_remote():
    logger.debug("init button A")
    # Button A
    btnA = DigitalInOut(board.D5)
    btnA.direction = Direction.INPUT
    btnA.pull = Pull.UP

# logger.debug("init button B")
# # Button B
# btnB = DigitalInOut(board.D6)
# btnB.direction = Direction.INPUT
# btnB.pull = Pull.UP
#
# logger.debug("init button C")
#
# # Button C
# btnC = DigitalInOut(board.D12)
# btnC.direction = Direction.INPUT
# btnC.pull = Pull.UP

logger.debug("init i2c interface")

# Create the I2C interface.
i2c = busio.I2C(board.SCL, board.SDA)

logger.debug("init oled display")

# 128x32 OLED Display
reset_pin = DigitalInOut(board.D4)
display = adafruit_ssd1306.SSD1306_I2C(128, 32, i2c, reset=reset_pin)

# Clear the display.
display.fill(0)
display.show()
display.fill(1)
display.show()
time.sleep(.3)
display.fill(0)
display.show()
time.sleep(.3)
display.fill(1)
display.show()
time.sleep(.3)
display.fill(0)
display.show()

# Create blank image for drawing
# Make sure to create image with mode '1' for 1-bit color.
width = display.width
height = display.height
image = Image.new('1', (width, height))

# Get drawing object to draw on image
draw = ImageDraw.Draw(image)


# Draw a black filled box to clear the image.
def blank_disp():
    draw.rectangle((0, 0, width, height), outline=0, fill=0)


blank_disp()

# Draw some shapes
# First define some constants to allow easy resizing of shapes
padding = -2
top = padding
bottom = height - padding
# Move left to right keeping track of the current x position
# for drawing shapes.
x = 0

# Load nice silkscreen font
logger.debug("init display font")
font = ImageFont.truetype('/home/pi/1/slkscr.ttf')

logger.debug("init lora radio")

# Configure LoRa Radio
RADIO_FREQ = 915.0
XMIT_DB = 23
CS = DigitalInOut(board.CE1)
RESET = DigitalInOut(board.D25)
spi = busio.SPI(board.SCK, MOSI=board.MOSI, MISO=board.MISO)
rfm9x = adafruit_rfm9x.RFM9x(spi, CS, RESET, RADIO_FREQ)
rfm9x.enable_crc = True
rfm9x.tx_power = XMIT_DB
packet = None
prev_packet = None

logger.info("Output Power -- {} dB".format(XMIT_DB))
logger.info("Listening on {} MHz".format(RADIO_FREQ))


def validate_preamble():
    global prev_packet
    preamble = prev_packet[0:3]
    if preamble == PREAMBLE:
        return True
    return False


def validate_time(ts1, ts2):
    if abs(ts1 - ts2) > ALLOWABLE_TIME_ERROR:
        return False
    return True


def log_unknown_packet():
    global prev_packet
    rlog_path = "/home/pi/1/raw/{}.dat".format(time.time())
    with open(rlog_path, 'wb') as w:
        logger.info("Packet is Unknown")
        logger.info("Writing packet to {}".format(rlog_path))
        w.write(prev_packet)
        w.flush()


# line is cardinal: 1-4
def print_oled(line, text):
    # we should never need this; should is a dirty word
    if line < 1:
        line = 0
    # but we convert to ordinal because pixel math
    if line > 1:
        line = line - 1
    # anything below the last line just prints over the last line
    if line > 3:
        line = 3
    draw.text((x, top + (line * 8)), text, font=font, fill=255)


def handle_packet_remote(recv_msg):
    if recv_msg.channel == CHANNEL:
        logger.debug("Packet on correct channel")
        if recv_msg.type == messages_pb2.GrageDoorMessage.RECVD:
            logger.debug("Packet Type: RECVD")
            if recv_msg.mac == last_sent_mac:
                # draw.text((x, top + 24), "ACK", font=font, fill=255)
                print_oled(4, "ACK")
                logger.debug("RECV ACKs last sent packet")
            else:
                logger.debug("RECV ACKs unknown or forgotten packet")

        elif recv_msg.type == messages_pb2.GrageDoorMessage.DENIED_OOB_TIME:
            logger.debug("Packet Type: DENIED_OOB_TIME")
            if recv_msg.mac == last_sent_mac:
                # draw.text((x, top + 24), "DENIED: OOB TIME", font=font, fill=255)
                print_oled(4, "DENIED: OOB TIME")
                logger.warning("RECV DENIES last sent packet")
            else:
                logger.warning("RECV DENIES unknown or forgotten packet")
        elif recv_msg.type == messages_pb2.GrageDoorMessage.DENIED_UNAUTH:
            logger.debug("Packet Type: DENIED_UNAUTH")
            if recv_msg.mac == last_sent_mac:
                # draw.text((x, top + 24), "DENIED: UNAUTH", font=font, fill=255)
                print_oled(4, "DENIED: UNAUTH")
                logger.warning("RECV DENIES last sent packet")
            else:
                logger.warning("RECV DENIES unknown or forgotten packet")
        elif recv_msg.type == messages_pb2.GrageDoorMessage.DENIED_OOB_GEOFENCE:
            logger.debug("Packet Type: DENIED_OOB_GEOFENCE")
            if recv_msg.mac == last_sent_mac:
                # draw.text((x, top + 24), "DENIED: OOB GEO", font=font, fill=255)
                print_oled(4, "DENIED: OOB GEO")
                logger.warning("RECV DENIES last sent packet")
            else:
                logger.warning("RECV DENIES unknown or forgotten packet")
    else:
        logger.debug("Packet on wrong channel; ignoring")


def handle_packet_server(recv_msg):
    if recv_msg.type == messages_pb2.GrageDoorMessage.OPEN:
        if not validate_time(recv_msg.ts, int(time.time())):
            logger.warning("Packet failed time verification")
            ts_oob_msg = messages_pb2.GrageDoorMessage()
            ts_oob_msg.id = ID
            ts_oob_msg.channel = recv_msg.channel
            ts_oob_msg.type = messages_pb2.GrageDoorMessage.DENIED_OOB_TIME
            ts_oob_msg.mac = bytes(recv_msg.mac)
            ts_oob_msg.ts = int(time.time())
            rfm9x.send(PREAMBLE + bytes(ts_oob_msg.SerializeToString()))
            logger.warning("DENIED_OOB_TIME response sent")
            return

        logger.debug("Packet Type: OPEN")
        nonce64 = codecs.encode(recv_msg.nonce, "base64")
        data = "{}\n{}\n{}\n{}\n{}\n{}\n".format(nonce64, recv_msg.ts, recv_msg.type, recv_msg.nmea, recv_msg.channel,
                                                 recv_msg.id)

        d = hmac.digest(SECRET, bytes(data, 'ascii'), hashlib.sha3_256)
        if hmac.compare_digest(d, recv_msg.mac):
            logger.debug("Packet is verified")
            time.sleep(.3)
            logger.info("Opening garage door")
            automationhat.relay.one.on()
            time.sleep(RELAY_TIME)
            automationhat.relay.one.off()
            resp_msg = messages_pb2.GrageDoorMessage()
            resp_msg.id = ID
            resp_msg.channel = recv_msg.channel
            resp_msg.type = messages_pb2.GrageDoorMessage.RECVD
            resp_msg.mac = bytes(recv_msg.mac)
            resp_msg.ts = int(time.time())
            rfm9x.send(PREAMBLE + bytes(resp_msg.SerializeToString()))
            logger.info("RECVD response sent")
            # draw.text((x, top + 24), "Sent ACK", font=font, fill=255)
        else:
            logger.warning("Packet failed digest verification")
            unauth_msg = messages_pb2.GrageDoorMessage()
            unauth_msg.id = ID
            unauth_msg.channel = recv_msg.channel
            unauth_msg.type = messages_pb2.GrageDoorMessage.DENIED_UNAUTH
            unauth_msg.mac = bytes(recv_msg.mac)
            unauth_msg.ts = int(time.time())
            rfm9x.send(PREAMBLE + bytes(unauth_msg.SerializeToString()))
            logger.error("DENIED_UNAUTH response sent")
            # draw.text(x, top + 24), "Sent UNAUTH", font=font, fill=255)


def handle_packet(packet):
    recv_msg = messages_pb2.GrageDoorMessage()
    recv_msg.ParseFromString(packet)

    handlers = {
        "remote": handle_packet_remote,
        "server": handle_packet_server,
    }
    handler = handlers.get(ENV, lambda: 'Invalid Environment Setting')
    handler(recv_msg)


def send_open_message():
    global last_sent_mac
    logger.debug('generating nonce')
    nonce = get_random_bytes(16)
    nonce64 = codecs.encode(nonce, "base64")
    logger.debug('building OPEN message')
    my_msg = messages_pb2.GrageDoorMessage()
    my_msg.id = ID
    my_msg.nonce = nonce
    my_msg.channel = CHANNEL
    my_msg.type = messages_pb2.GrageDoorMessage.OPEN
    my_msg.ts = int(time.time())
    logger.debug('signing message')
    data = "{}\n{}\n{}\n{}\n{}\n{}\n".format(nonce64, my_msg.ts, my_msg.type, my_msg.nmea, my_msg.channel, my_msg.id)
    my_msg.mac = hmac.digest(SECRET, bytes(data, 'ascii'), hashlib.sha3_256)

    button_a_data = PREAMBLE + bytes(my_msg.SerializeToString())
    last_sent_mac = my_msg.mac
    len_data = len(button_a_data)
    logger.debug('sending OPEN packet')
    rfm9x.send(button_a_data)
    logger.debug("{} bytes sent".format(len_data))
    print_oled(1, "OPEN")
    # draw.text((x, top + 8), "OPEN", font=font, fill=255)


def run_client():
    global packet
    global prev_packet

    try:
        while True:
            packet = None
            blank_disp()
            # draw a box to clear the image
            # draw.text((x, top), "Qlikr - Listening", font=font, fill=255)

            # check for packet rx
            packet = rfm9x.receive()
            if packet is None:
                # draw.text((x, top + 8), "[Waiting for Packet]", font=font, fill=255)
                display.image(image)
                display.show()
            else:
                logger.info("Packet received -- RSSI: {} dB".format(rfm9x.rssi))
                print_oled(2, "[Packet Received]")
                # draw.text((x, top + 8), "[Packet Received]", font=font, fill=255)
                prev_packet = packet
                if validate_preamble():
                    logger.debug("Packet is Familiar")
                    handle_packet(prev_packet[3:])
                else:
                    log_unknown_packet()
                time.sleep(1)
            if is_remote():
                if not btnA.value:
                    # Send Button A
                    logger.debug('open button pressed')
                    send_open_message()
                # elif not btnB.value:
                #     # Send Button B
                #     display.fill(0)
                #     button_b_data = bytes("Button B!\r\n", "utf-8")
                #     rfm9x.send(button_b_data)
                #     display.text('Sent Button B!', 25, 15, 1)
                # elif not btnC.value:
                #     # Send Button C
                #     display.fill(0)
                #     button_c_data = bytes("Button C!\r\n", "utf-8")
                #     rfm9x.send(button_c_data)
                #     display.text('Sent Button C!', 25, 15, 1)

            display.image(image)
            display.show()
            time.sleep(0.1)
    except KeyboardInterrupt:
        logger.warning("\nShutting down due to user interrupt")
    finally:
        display.fill(0)
        display.show()


run_client()
