# Qlikr
RPI+LoRa Garage Door Opener Project for Raspberry PI, LoRa, and Python3.

## A Quick Apology
I write Go, Javascript, Ruby and sometimes Perl. This is my first attempt at Python. Also, this is to be considered a first-round write, so expect the code to be ugly. I have done very few abstractions, have not optimized my code, and haven't bothered with threading, yet.

Also, the `requirements.txt` file? I just wouldn't pay much attention to that yet. Still figuring that out.

## TL;DR
This project is an over-engineered solution to replacing the garage door clicker to our 40-yr old garage door (no replacement clickers to be had, do not want to replace the garage door opener, because it still works, because it's 40yrs old).

## Moar Description
The project consists of 2+ units based on raspberry pi's: 

- 1 base station, 
- and one or more remotes. 

They communicate via an RFM9x-based LoRa hat from Adafruit, and the base station. I used the 915 MHz version for my project, but you can use the 433 MHz--it doesn't really matter. The packets are "preambled" protocol buffers representing one of several defined messages. The "preamble" is technically a [magic number](https://en.wikipedia.org/wiki/Magic_number_%28programming%29), and is configurable in a `.env` file.

The `OPEN` message is inspired by [OAuth2 Mac Authentication Tokens](https://datatracker.ietf.org/doc/html/draft-ietf-oauth-v2-http-mac-02), making it verifiable (yes, it's really you opening the garage door, and not Nefarious Bob looking to burgle your house), and is "configurably resistant" to replay attacks.

## .env

### QLIKR_ENV="server|remote"
Set this to either `server` for the base station, or `remote` for a remote.

### QLIKR_ID
This can be any ASCII string, but keep it short. Must be unique.

### QLIKR_SECRET
This can be any ASCII string. **This must be the same on all units you want to work together on a common channel.** Length doesn't matter, but the shorter it is, the less secure it is. The longer it is, the longer it takes to hash. You have to choose the compromise, here, based on the compute power of your chosen raspberry pi. Using 30 characters on an RPi4 probably works great. 30 characters on a Pi Zero will make it chug just enough to have poor UX.

### QLIKR_CHANNEL
This can be any 32-bit unsigned integer. This gives you 2 billion options, while shaving a few bytes off the packet size.

### QLIKR_PREAMBLE
This can be any valid UTF-8 or ASCII string, but keep it short.

### QLIKR_ALLOWED_TIME_ERROR
Any unsigned integer `>= 0`. This is the allowed deviation in time measured in seconds.

Raspberry Pi's do not have a realtime clock, and are designed with the "expectation" that they'll be connected to the internet, allowing them to periodically update their clocks from the internet. But, it's reasonable to expect that a remote that lives in your car won't be connected to the internet much, if at all. Time drift will be caused by temperature, differences in supply voltage, time spent off, etc. Therefore, time will deviate between remote and base station. To prevent replay attacks to open the garage door, the units must "agree" on the time. This setting controls the amount of deviation you allow. The larger the number, the less you'll have to sync up the times, but the more susceptible you are to replay attacks.
