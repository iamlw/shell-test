#!/bin/bash
read -p "请输入月份" month
case $month in
"3" | "4" | "5")
    echo "春季"
    ;;
"6" | "7" | "8")
    echo "夏季"
    ;;
"9" | "10" | "11")
    echo "秋季"
    ;;
"12" | "1" | "2")
    echo "冬季"
    ;;
esac
    