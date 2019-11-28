#!/bin/sh
./hex2raw -i ans/level1.txt  | ./ctarget -q
./hex2raw -i ans/level2.txt  | ./ctarget -q
./hex2raw -i ans/level3.txt  | ./ctarget -q
./hex2raw -i ans/level4.txt  | ./rtarget -q
./hex2raw -i ans/level5.txt  | ./rtarget -q
