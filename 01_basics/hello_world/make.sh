#!/usr/bin/env bash

echo "Compiling..."
mkdir obj
clang++ -c ex1.cpp -o obj/ex1.o
echo "Linking..."
mkdir bin
clang++ obj/ex1.o -o bin/ex1
echo "Done!"
