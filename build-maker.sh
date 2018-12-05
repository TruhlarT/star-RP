#!/bin/bash

SRC="src"
INC="include"
DEST="StRoot/StUPCFilterMaker"

srclist=( StMuRpsCollection StMuRpsTrack StMuRpsTrackPoint StRpsCluster StRpsCollection StRpsPlane StRpsRomanPot StRpsTrack StRpsTrackPoint)

mkdir -p $DEST

i=0
for file in ${srclist[@]}
do
  cp -f $SRC"/"${srclist[$i]}".cxx" $DEST/
  cp -f $INC"/"${srclist[$i]}".h" $DEST/
  ((i++))
done

cons




























