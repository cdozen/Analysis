#!/bin/bash

BACKGROUNDS="../backgrounds/"
COMBINED=""

for file in "$BACKGROUNDS/*.tif"; do 
  COMBINED="$COMBINED $file"
done

./BackgroundCreator $COMBINED out.tif
