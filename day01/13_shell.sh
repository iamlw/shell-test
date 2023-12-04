#!/bin/bash
function add ()
{
    declare -i sum=0
    sum=$1+$2
    return $sum
}
