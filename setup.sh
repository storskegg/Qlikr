#!/bin/sh

# Update Pi and Python
sudo apt-get update && sudo apt-get dist-upgrade

sudo pip3 install --upgrade setuptools

ls /dev/i2c* /dev/spi*

# Install Python Libs
sudo pip3 install RPI.GPIO
sudo pip3 install adafruit-blinka
sudo pip3 install adafruit-circuitpython-ssd1306
sudo pip3 install adafruit-circuitpython-framebuf
sudo pip3 install adafruit-circuitpython-rfm9x
