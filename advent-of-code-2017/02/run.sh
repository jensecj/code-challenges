#!/bin/sh
clang++ -std=c++17 -MJ compile_commands.json -Wall -Wpedantic main.cpp -o main
# create a compilation database for rtags
sed -i -e '1s/^/[\n/' -e '$s/,$/\n]/' compile_commands.json
# run and time out program
time ./main <<< $(cat input.in)
