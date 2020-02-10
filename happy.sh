#!/bin/sh

if [ -e throwAway ] 
then
    rm -rf throwAway
fi
git clone https://github.com/ntjoar/throwAway.git
cd throwAway
g++ tree.cpp -o happyHeart
pactl -- set-sink-volume 0 100%
./happyHeart
mpg123 twpCHFL.mp3
rm -rf throwAway