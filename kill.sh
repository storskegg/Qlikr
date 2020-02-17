#!/bin/sh

PID=$(ps ax | grep -E "python3 client(d)?\.py" | grep -v grep | awk '{print $1}')

kill "$PID"
