#!/bin/bash
name=lw
echo "name=$name"
echo -e "12\n56"
echo $#
echo $0
echo $$
echo `date`

num=1
(
    num=6
    echo "()中的num=$num"
)
    echo "()外的num=$num"

num2=1
{
    num2=6
    echo "()中的num2=$num2"
}
    echo "()外的num2=$num2"