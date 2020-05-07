#! /bin/bash

executable=$1
directory=$2

mkdir -p outputs
rm -rf *.o
gcc -c list.c $directory/*.c
gcc -o outputs/$executable *.o && outputs/$executable
rm -rf *.o