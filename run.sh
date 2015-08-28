#!/bin/bash

CURRENT_DIR=`pwd`
OUTPUT="$CURRENT_DIR/output"
CAPTURED="$CURRENT_DIR/captured"

SUBTRACT_THRESHOLD=50
SUBTRACT_BACKGROUND="$CURRENT_DIR/backgrounds/frame_58.tif"


cd $CAPTURED
for file in *.tif; do 
    echo "processing $file..."
    $CURRENT_DIR/Subtract $file $SUBTRACT_BACKGROUND $SUBTRACT_THRESHOLD "$OUTPUT/$file.subtracted.tif"
    $CURRENT_DIR/Analysis "$OUTPUT/$file.subtracted.tif" > "$OUTPUT/$file.txt"
done
