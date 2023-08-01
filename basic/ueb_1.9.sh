#!/bin/sh	
# Programmargumente
# Anzahl
echo $# 

# Liste
echo $*
echo $@

# ProzessId
echo $$

# Argumente
echo The 1st arg is $0
echo The 2nd arg is $1
echo The 3rd arg is $2

echo Ergebnis=`expr $1 + $2`