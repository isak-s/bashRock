#!/bin/sh
iterations=$1

# aplay /dev/urandom -r 4000 -s 400
for i in $(seq 1 $iterations)
do
aplay /dev/urandom -r 10000 -s 200

aplay /dev/urandom -r 10000 -s 200

aplay /dev/urandom -r 2000 -s 400 & aplay "./drums.sh" -r 4000 -s 400
sleep 0.1
aplay /dev/urandom -r 10000 -s 200
aplay /dev/urandom -r 10000 -s 200
aplay /dev/urandom -r 4000 -s 400 & aplay "./drums.sh" -r 8000 -s 400
sleep 0.1

done
