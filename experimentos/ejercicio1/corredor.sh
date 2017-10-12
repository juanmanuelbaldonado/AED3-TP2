#!/bin/bash

echo Test 1: Variando la cantidad de trabajos
python3 ejercicio1_experimento1.py | ../../ejercicio1 -b ../../resultados/ejercicio1/ej1_variando_cant_trabajos.csv > ejercicio1_ex1.out

echo Test 2: Variando la amplitud entre el costo minimo y el maximo
python3 ejercicio1_experimento2.py | ../../ejercicio1 -b ../../resultados/ejercicio1/ej1_variando_amplitud_costos.csv > ejercicio1_ex2.out

echo Test 3: Variando como disminuye el costo, cuanto mayor es el indice del trabajo
python3 ejercicio1_experimento3.py | ../../ejercicio1 -b ../../resultados/ejercicio1/ej1_disminuyendo_amplitud_costos.csv > ejercicio1_ex3.out