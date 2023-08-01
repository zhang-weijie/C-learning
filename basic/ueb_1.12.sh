#!/bin/sh	# 1. Zeile: Festlegen der Shell
# Anzahl der Zeichen zweier Dateien berechnen und deren Namen angeben
a=`wc -c $1 | cut -f 1 -d " "`
b=`wc -c $2 | cut -f 1 -d " "`

echo $a
echo $b
echo Gesamtzahl der Zeichen = `expr $a + $b`
exit 0