#!/bin/sh

for filename in ./raw/*.dat; do
  [ -e "$filename" ] || continue
  fsize=$(wc -c <"$filename")
  if [ 0 -eq "$fsize" ]; then
    echo Scrubbing "$filename"
    rm "$filename"
  else
    newfilename="${filename%.*}".pkt
    echo Renaming "$filename" to "$newfilename"
    mv "$filename" "$newfilename"
  fi
done
