#!/bin/bash
declare -i i=0
while [ $i -le 100 ]
do
    num=$((i%2))
    if [ $num -eq 0 ];then
        echo $i
    fi
    i=$i+1
done