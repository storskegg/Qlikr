#!/bin/sh

# Update Pi and Python
sudo apt-get update && sudo apt-get dist-upgrade -y

sudo apt-get install python3-pip -y

sudo pip3 install --upgrade setuptools

ls /dev/i2c* /dev/spi*

# Install Python Libs
sudo pip3 install -r requirements.txt
sudo pip3 install RPI.GPIO
sudo pip3 install adafruit-blinka
sudo pip3 install adafruit-circuitpython-ssd1306
sudo pip3 install adafruit-circuitpython-framebuf
sudo pip3 install adafruit-circuitpython-rfm9x
sudo pip3 install -U python-dotenv
