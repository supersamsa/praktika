#!/bin/bash

CPU_MODEL=$(grep "model name" /proc/cpuinfo | head -1 | cut -d: -f2 | sed 's/^ *//')
L1_CACHE=$(grep "cache size" /proc/cpuinfo | head -1 | awk '{print $4}')

read -p "Введите число N: " NUMBER

printf "%s\n%s\n$NUMBER\n" "$CPU_MODEL" "$L1_CACHE" | ./research