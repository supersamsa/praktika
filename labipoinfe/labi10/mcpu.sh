#!/bin/bash

gcc -o cpuu cpuu.c
CPU_NAME=$(grep "model name" /proc/cpuinfo | head -1 | awk -F: '{print $2}' | sed 's/^[ \t]*//')
L1_SIZE=$(grep "cache size" /proc/cpuinfo | head -1 | awk -F: '{print $2}' | sed 's/^[ \t]*//' | awk '{print $1}')
read USER_NUMBER
echo "$CPU_NAME" > data
echo "$L1_SIZE" >> data
echo "$USER_NUMBER" >> data

./cpuu < data

rm data