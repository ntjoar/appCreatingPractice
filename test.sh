#!/bin/sh

g++ tree.cpp -o happyHeart
sudo osascript -e "set Volume 2"
./happyHeart; osascript -e 'tell application "Terminal" to activate'