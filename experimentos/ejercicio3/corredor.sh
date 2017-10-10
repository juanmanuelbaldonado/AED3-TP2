#!/bin/bash

for i in {1..50..1}
	do 
		echo variando nodos con primO en $i con min
		../../ejercicio3 1 < ej3_2090_1 > "../../resultados/ejercicio3/2090/"$i+100".csv"
		../../ejercicio3 1 < ej3_2090_2 > "../../resultados/ejercicio3/2090/"$i+200".csv"
		../../ejercicio3 1 < ej3_2090_3 > "../../resultados/ejercicio3/2090/"$i+300".csv"
		../../ejercicio3 1 < ej3_2090_4 > "../../resultados/ejercicio3/2090/"$i+300".csv"
		../../ejercicio3 1 < ej3_2090_5 > "../../resultados/ejercicio3/2090/"$i+500".csv"
done

for i in {1..50..1}
	do 
		echo variando nodos con primO en $i con min
		../../ejercicio3 1 < ej3_4590_1 > "../../resultados/ejercicio3/4590/"$i+100".csv"
		../../ejercicio3 1 < ej3_4590_2 > "../../resultados/ejercicio3/4590/"$i+200".csv"
		../../ejercicio3 1 < ej3_4590_3 > "../../resultados/ejercicio3/4590/"$i+300".csv"
		../../ejercicio3 1 < ej3_4590_4 > "../../resultados/ejercicio3/4590/"$i+300".csv"
		../../ejercicio3 1 < ej3_4590_5 > "../../resultados/ejercicio3/4590/"$i+500".csv"
done

for i in {1..50..1}
	do 
		echo variando nodos con primO en $i con min
		../../ejercicio3 1 < ej3_9090_1 > "../../resultados/ejercicio3/9090/"$i+100".csv"
		../../ejercicio3 1 < ej3_9090_2 > "../../resultados/ejercicio3/9090/"$i+200".csv"
		../../ejercicio3 1 < ej3_9090_3 > "../../resultados/ejercicio3/9090/"$i+300".csv"
		../../ejercicio3 1 < ej3_9090_4 > "../../resultados/ejercicio3/9090/"$i+300".csv"
		../../ejercicio3 1 < ej3_9090_5 > "../../resultados/ejercicio3/9090/"$i+500".csv"
done

for i in {1..50..1}
	do 
		echo variando nodos con primO en $i con min
		../../ejercicio3 1 < fabs90_1 > "../../resultados/ejercicio3/fabs90/"$i+100".csv"
		../../ejercicio3 1 < fabs90_2 > "../../resultados/ejercicio3/fabs90/"$i+200".csv"
		../../ejercicio3 1 < fabs90_3 > "../../resultados/ejercicio3/fabs90/"$i+300".csv"
		../../ejercicio3 1 < fabs90_4 > "../../resultados/ejercicio3/fabs90/"$i+300".csv"
		../../ejercicio3 1 < fabs90_5 > "../../resultados/ejercicio3/fabs90/"$i+500".csv"
done