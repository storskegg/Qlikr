#!/bin/sh

mkdir /home/pi/log
mkdir /home/pi/1/raw
mkdir /home/pi/tmp

# Update Pi and Python
sudo apt-get update && sudo apt-get dist-upgrade -y

sudo apt-get install python3-pip libjpeg-dev zlib1g-dev libfreetype6-dev liblcms1-dev libopenjp2-7 libtiff5 -y

sudo pip3 install --upgrade setuptools

ls /dev/i2c* /dev/spi*

# Install Python Libs w/ sudo so they're available for all users (e.g. root)
sudo pip3 install -r requirements.txt
sudo pip3 install RPI.GPIO
sudo pip3 install adafruit-blinka
sudo pip3 install adafruit-circuitpython-ssd1306
sudo pip3 install adafruit-circuitpython-framebuf
sudo pip3 install adafruit-circuitpython-rfm9x
sudo pip3 install -U python-dotenv python-daemon

# Pimoroni libs
curl https://get.pimoroni.com/automationhat | bash

# Install UUGear libs
wget https://project-downloads.drogon.net/wiringpi-latest.deb

sudo dpkg -i wiringpi-latest.deb

# insert the following line before `exit 0` in rc.local
sudo sed -i -e "/exit 0/ i su pi -c \'/usr/bin/python3 /home/pi/1/clientd.py > /home/pi/log/qlikr_rclocal.log 2>&1\' &\n" /etc/rc.local
