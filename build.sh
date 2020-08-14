#!/bin/bash

echo Compiling...

g++ src/*.cpp -std=c++14 -lsfml-window -lsfml-graphics -lsfml-system -o game -Werror

exit
