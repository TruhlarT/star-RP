#!/bin/bash
# A sample Bash script, by Trhlar

PathToFile="/home/truhlar/Desktop/STAR/VU/star-RP"
PathToCreate="/home/truhlar/Desktop/STAR/VU/star-RP/New/"

for entry in "$PathToFile"/*.cxx
do
	 soubor=$(echo "$entry" | cut -d '/' -f 8)
	 cat "$entry" | cut -d ' ' -f 5-200 >> "$PathToCreate$soubor"
done

for entry in "$PathToFile"/*.h
do
	soubor=$(echo "$entry" | cut -d '/' -f 8)
	 cat "$entry" | cut -d ' ' -f 5-200 >> "$PathToCreate$soubor"
done