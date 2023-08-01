#!/bin/sh
LIMIT=600 # Anzahl der Wuerfe
Nclass=6 # Anzahl der "Wuerfeloberflaechen"

i=0 # Initialisierungen
erg=0
mittel=0
schwank=0
sqrt_erg=0

while [ $i -lt $Nclass ]; do
	wuerfel[$i]=0
	i=`expr $i + 1`
done

sqrt() { # Berechnung der Quadratwurzel
	i=-1
	quadrat=0
	
	if [ $1 -lt 0 ]; then
		echo Error sqrt: negatives Argument
		exit 1
	fi
	
	while [ $quadrat -lt $1 ]; do
		i=`expr $i + 1`
		quadrat=`expr $i \* $i`
	done
	
 sqrt_erg=$i
}

 # Wuerfeln ...
while [ $i -lt $LIMIT ]; do
	erg=`expr $RANDOM % $Nclass`
	wuerfel[$erg]=`expr ${wuerfel[$erg]} + 1`
	i=`expr $i + 1`
done

 # Ausgabe Wuerfelergebnis
echo 
echo Folgende Augenzahlen wurden geworfen:
echo "( 1er 2er 3er 4er 5er 6er )"
echo " "${wuerfel[*]}
echo
 
 # Bestimmung der erlaubten Schwankung
mittel=`expr $LIMIT / $Nclass`
sqrt $mittel # Aufruf der Funktion sqrt()
schwank=$sqrt_erg
echo Kontrolle:
echo " "Theoret. Bereich = $mittel +/- $schwank
echo
exit 0
