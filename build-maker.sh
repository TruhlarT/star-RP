#!/bin/bash

SRC="src"
INC="include"
DEST="StRoot/StRPTest"

srclist=( StUPCRpsPreCollection StUPCRpsPreTrack StUPCRpsPreTrackPoint StUPCRpsCollection StUPCRpsRomanPot StUPCRpsPlane StUPCRpsCluster StUPCRpsTrack StUPCRpsTrackPoint StRPEvent StUPCFilterRPUtil)


mkdir -p $DEST

i=0
for file in ${srclist[@]}
do
  cp -f $SRC"/"${srclist[$i]}".cxx" $DEST/
  cp -f $INC"/"${srclist[$i]}".h" $DEST/
  ((i++))
done

cons




























