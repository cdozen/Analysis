#!/bin/bash

for file in output/*.tif; do 
#   echo $file
    ./Analysis $file > "$file.txt"
done
