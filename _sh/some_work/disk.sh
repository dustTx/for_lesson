#!/bin/bash

Time=`date +"%Y-%m-%d__%H:%M:%S"`

num=$[ `df -hT | wc -l`-1 ]

sum=`df -ml | awk '{print $2,$3}' | sed '1d' | awk '{sum += $1};END {print sum}'`









echo "$Time $sum "

