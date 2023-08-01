#!/bin/sh

var=$1

case $var in
	j*|J*)
		echo "begins with j or J"
	;;
	*)
		echo "begins with neither j nor J"
	;;
esac