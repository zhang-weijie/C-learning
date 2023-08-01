#!/bin/sh

min=$1
max=$2

function isNumber {
	re='^[+-]?[0-9]+([.][0-9]+)?$'

	if ! [[ $1 =~ $re ]]; then
	   echo "error: '$1' ist keine Zahl"; 
	   exit 1
	fi
}

isNumber $min
isNumber $max

if [ $min -gt $max ]; then
	echo "Ungültiges Interval"
	exit 1
fi

sum=0
output=""

while [ $min -lt $max ]; do
        output="$output$min+"
        sum=` expr $sum + $min `
        min=` expr $min + 1 `
done
sum=` expr $sum + $max `
output="$output$max"
echo $output=$sum
