#!/bin/sh

name=$1
dateitype=$(file $name)

case $dateitype in 
	*ASCII*)
		echo "ASCII-Datei"
		cat $1
		;;
	*gzip*)
		echo "GZ-Datei"
		gunzip $1
		;;
	*tar*)
		echo "TAR-Datei"
		if [ ! -d tar ]; then
			mkdir tar
		fi
		cd tar
		tar -xvkf ../$1
		;;
	*)
		echo "unbekannter Dateityp" `file $1`
		;;
esac

exit 0