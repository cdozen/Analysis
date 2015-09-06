#!/bin/bash

CURRENT_DIR=`pwd`

for file in $1/*; do
    if [[ $file == *".dsc" ]]
    then
        continue
    fi
    FILE_NAME=`echo "$file" | sed "s/.*\///"`
    echo "processing $FILE_NAME..."
    ./TimePix2Im $file "$2/$FILE_NAME.tif"
done

cd $CURRENT_DIR
