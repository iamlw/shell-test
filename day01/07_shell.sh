#!/bin/bash
filename=""
#read -p 文件名 filename
#test -e $filename
#echo "文件是否存在：$?"

test -f $filename
echo "是文件吗$?"

[ -r $filename ]
echo "可读吗$?"

str="6"
test -z $str
echo -e "是否为空？\t$?"