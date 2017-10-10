#!/bin/bash


for i in {1..50..1}
	do 
		echo variando aristas con primO en $i con min
		../../ejercicio2 1 1 < aristas > "../../resultados/ejercicio2/primO_aristas/"$i+100".csv"
done

for i in {1..50..1}
	do 
		echo variando aristas con primC en $i con min
		../../ejercicio2 1 0 < aristas > "../../resultados/ejercicio2/primC_aristas/"$i+100".csv"
done
