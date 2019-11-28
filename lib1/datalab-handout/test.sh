#!/bin/sh

./dlc bits.c
make clean
make
./btest
./driver.pl
