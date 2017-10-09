#!/bin/bash

for i in {1..50..1}
	do 
		echo variando nodos con primO en $i con min
		./ejercicio2 1 1 < min400_1 > "./resultados/ejercicio2/primC_min/"$i+100".csv"
		./ejercicio2 1 1 < min400_2 > "./resultados/ejercicio2/primC_min/"$i+200".csv"
		./ejercicio2 1 1 < min400_3 > "./resultados/ejercicio2/primC_min/"$i+300".csv"
		./ejercicio2 1 1 < min400_4 > "./resultados/ejercicio2/primC_min/"$i+400".csv"
		./ejercicio2 1 1 < min400_5 > "./resultados/ejercicio2/primC_min/"$i+500".csv"
done

for i in {1..50..1}
	do 
		echo variando nodos con primC en $i con min
		./ejercicio2 1 0 < min400_1 > "./resultados/ejercicio2/primO_min/"$i+100".csv"
		./ejercicio2 1 0 < min400_2 > "./resultados/ejercicio2/primO_min/"$i+200".csv"
		./ejercicio2 1 0 < min400_3 > "./resultados/ejercicio2/primO_min/"$i+300".csv"
		./ejercicio2 1 0 < min400_4 > "./resultados/ejercicio2/primO_min/"$i+400".csv"
		./ejercicio2 1 0 < min400_5 > "./resultados/ejercicio2/primO_min/"$i+500".csv"
done


for i in {1..50..1}
	do 
		echo variando nodos con primO en $i con med
		./ejercicio2 1 1 < med400_1 > "./resultados/ejercicio2/primO_med/"$i+100".csv"
		./ejercicio2 1 1 < med400_2 > "./resultados/ejercicio2/primO_med/"$i+200".csv"
		./ejercicio2 1 1 < med400_3 > "./resultados/ejercicio2/primO_med/"$i+300".csv"
		./ejercicio2 1 1 < med400_4 > "./resultados/ejercicio2/primO_med/"$i+400".csv"
		./ejercicio2 1 1 < med400_5 > "./resultados/ejercicio2/primO_med/"$i+500".csv"
done

for i in {1..50..1}
	do 
		echo variando nodos con primC en $i con med
		./ejercicio2 1 0 < med400_1 > "./resultados/ejercicio2/primC_med/"$i+100".csv"
		./ejercicio2 1 0 < med400_2 > "./resultados/ejercicio2/primC_med/"$i+200".csv"
		./ejercicio2 1 0 < med400_3 > "./resultados/ejercicio2/primC_med/"$i+300".csv"
		./ejercicio2 1 0 < med400_4 > "./resultados/ejercicio2/primC_med/"$i+400".csv"
		./ejercicio2 1 0 < med400_5 > "./resultados/ejercicio2/primC_med/"$i+500".csv"
done

for i in {1..50..1}
	do 
		echo variando nodos con primO en $i con max
		./ejercicio2 1 1 < max400_1 > "./resultados/ejercicio2/primO_max/"$i+100".csv"
		./ejercicio2 1 1 < max400_2 > "./resultados/ejercicio2/primO_max/"$i+200".csv"
		./ejercicio2 1 1 < max400_3 > "./resultados/ejercicio2/primO_max/"$i+300".csv"
		./ejercicio2 1 1 < max400_4 > "./resultados/ejercicio2/primO_max/"$i+400".csv"
		./ejercicio2 1 1 < max400_5 > "./resultados/ejercicio2/primO_max/"$i+500".csv"
done

for i in {1..50..1}
	do 
		echo variando nodos con primC en $i con max
		./ejercicio2 1 0 < max400_1 > "./resultados/ejercicio2/primC_max/"$i+100".csv"
		./ejercicio2 1 0 < max400_2 > "./resultados/ejercicio2/primC_max/"$i+200".csv"
		./ejercicio2 1 0 < max400_3 > "./resultados/ejercicio2/primC_max/"$i+300".csv"
		./ejercicio2 1 0 < max400_4 > "./resultados/ejercicio2/primC_max/"$i+400".csv"
		./ejercicio2 1 0 < max400_5 > "./resultados/ejercicio2/primC_max/"$i+500".csv"
done