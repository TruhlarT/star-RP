#!/bin/bash

SRC="src"
INC="include"
DEST="StRoot/StRPTest"

srclist=( StRpsPreCollection StRpsPreTrack StRpsPreTrackPoint StRpsCollection StRpsRomanPot StRpsPlane StRpsCluster StRpsTrack StRpsTrackPoint)


mkdir -p $DEST

i=0
for file in ${srclist[@]}
do
  cp -f $SRC"/"${srclist[$i]}".cxx" $DEST/
  cp -f $INC"/"${srclist[$i]}".h" $DEST/
  ((i++))
done

cons




























