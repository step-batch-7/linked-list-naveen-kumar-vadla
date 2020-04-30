#! /bin/bash

executable=$1

mkdir -p outputs
rm -rf *.o
gcc -c *.c
gcc -o outputs/$executable *.o && outputs/$executable
rm -rf *.o