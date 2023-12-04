#!/bin/bash
# num=6
# echo ${num:=10}
if [ -e "a.txt" ];then
    echo "不管"
else
    touch "a.txt"
fi