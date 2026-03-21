#!/bin/sh
if [ -d "$1" ]; then
    tar -cJ $1 > backup-$(date +%Y-%m-%d).txz
else
    echo "Ожидалось $0 <dir>"
fi
