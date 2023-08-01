#!/bin/sh
count=0
while true; do
        read LINE
        count=`expr $count + 1`
        [ $count -lt 2 ] && continue
        [ $count -gt 3 ] && break
        echo $LINE 
done < read.data
