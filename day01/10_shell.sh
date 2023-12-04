#!/bin/bash

declare -i sum=0
declare -i i=0
for((i=0;i<101;i++))
do
    sum=$sum+$i
done
echo $sum