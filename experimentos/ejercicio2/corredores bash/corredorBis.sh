#!/bin/bash

for i in {1..50..1}
	do 
		echo variando aristas con primO en $i
		./ejercicio2 1 1 < aristas200_1 > "./resultados/ejercicio2/primO_aristas/"$i+100".csv"
		./ejercicio2 1 1 < aristas200_2 > "./resultados/ejercicio2/primO_aristas/"$i+200".csv"
		./ejercicio2 1 1 < aristas200_3 > "./resultados/ejercicio2/primO_aristas/"$i+300".csv"
		./ejercicio2 1 1 < aristas200_4 > "./resultados/ejercicio2/primO_aristas/"$i+400".csv"
		./ejercicio2 1 1 < aristas200_5 > "./resultados/ejercicio2/primO_aristas/"$i+500".csv"
done

for i in {1..50..1}
	do 
		echo variando aristas con primC en $i
		./ejercicio2 1 0 < aristas200_1 > "./resultados/ejercicio2/primC_aristas/"$i+100".csv"
		./ejercicio2 1 0 < aristas200_2 > "./resultados/ejercicio2/primC_aristas/"$i+200".csv"
		./ejercicio2 1 0 < aristas200_3 > "./resultados/ejercicio2/primC_aristas/"$i+300".csv"
		./ejercicio2 1 0 < aristas200_4 > "./resultados/ejercicio2/primC_aristas/"$i+400".csv"
		./ejercicio2 1 0 < aristas200_5 > "./resultados/ejercicio2/primC_aristas/"$i+500".csv"
done