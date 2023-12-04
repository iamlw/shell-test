#!/bin.bash
declare -i num=0
until [ $num -eq 101 ]
do
    echo $num
    num=$num+1
done