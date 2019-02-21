#!/bin/bash

function Usage() {
    echo "Usage $0"
}

if [[ $# -ne 1 ]]; then
    Usage
    exit 1
fi

last=$1

Time=`date +"%Y-%m-%d__%H:%M:%S"`

total=`free | awk '{print $2}' | sed -n '2p'`
total=$[ $total/1024 ]
used=`free | awk '{print $3}' | sed -n '2p'`
used=$[ $used/1024 ]
free=`free | awk '{print $4}' | sed -n '2p'`
free=$[ $free/1024 ]

memperc=`echo "scale=3; $used/$total*100" | bc`
memperc=`printf "%.1f\n" "$memperc"`

now=`echo "scale=3; $last*0.3+$memperc*0.7" | bc`
now=`printf "%.1f\n" "$now"`

echo "$Time ${total}M $free ${memperc}% ${now}%"





