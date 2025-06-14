#!/bin/sh

while true
do
aplay /dev/urandom -r 2000 -s 400 & aplay "./drums.sh" -r 4000 -s 400

sleep 0.15

aplay /dev/urandom -r 2000 -s 400 & aplay "./drums.sh" -r 4000 -s 400

sleep 0.15

aplay /dev/urandom -r 4000 -s 400 & aplay "./drums.sh" -r 8000 -s 400

sleep 0.6
done