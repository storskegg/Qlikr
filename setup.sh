#!/bin/sh

# Update Pi and Python
sudo apt-get update && sudo apt-get dist-upgrade -y

sudo apt-get install python3-pip libjpeg-dev zlib1g-dev libfreetype6-dev liblcms1-dev libopenjp2-7 libtiff5 -y

sudo pip3 install --upgrade setuptools

ls /dev/i2c* /dev/spi*

# Install Python Libs
sudo pip3 install -r requirements.txt
sudo pip3 install RPI.GPIO
sudo pip3 install adafruit-blinka
sudo pip3 install adafruit-circuitpython-ssd1306
sudo pip3 install adafruit-circuitpython-framebuf
sudo pip3 install adafruit-circuitpython-rfm9x
sudo pip3 install -U python-dotenv python-daemon

# Pimoroni libs
curl https://get.pimoroni.com/automationhat | bash

# sudo pip3 list --outdated --format=freeze | grep -v '^\-e' | cut -d = -f 1  | xargs -n1 sudo pip3 install -U
