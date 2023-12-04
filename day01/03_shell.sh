#!/bin/bash
#readonly DATA=1
DATA=1

NAME=lw
echo "NAME"=$NAME
DATA=100
echo "DATA"=$DATA

unset NAME
echo "NAME"=$NAME

export DATA
env