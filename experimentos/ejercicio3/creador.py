#!/usr/bin/python

import random
import math

def componentes(fab,cli,comp):
	fabricas = []
	for i in range(0,fab):
		fabricas.append(i+1)
	
	clientes = []
	for i in range(0,cli):
		clientes.append(i+1+fab)
	
	componentes = []
	for i in range(0,comp):
		aux = []
		aux.append(fabricas[i])
	
		componentes.append(aux)
	
	for i in range(0,comp):
		fabricas.remove(i+1)
	
	i = 0
	while len(clientes) != 0:
		secure_random = random.SystemRandom()
		cliente = secure_random.choice(clientes)
		
		componentes[i].append(cliente)
	
		clientes.remove(cliente)
		
		i = i+1
		if i == len(componentes):
			i = 0
	
	
	while len(fabricas) != 0:
		secure_random = random.SystemRandom()
		fabrica = secure_random.choice(fabricas)
		
		componentes[i].append(fabrica)
	
		fabricas.remove(fabrica)
	
		i = i+1
		if i == len(componentes):
			i = 0
	
	pesos = []
	nodos = fab + cli
	maxN = (nodos*(nodos-1))/2
	for i in range(1, int(maxN)+1):
		pesos.append(i)
	
	instancias = []
	for c in range(0,len(componentes)):
		aux = []
		for i in range(0,len(componentes[c])-1):
			for j in range(i+1,len(componentes[c])):
				aux.append((componentes[c][i],componentes[c][j]))
		instancias.append(aux)

	print(instancias)

	arst = 0
	for i in range(0,len(instancias)):
		for _ in range(0,len(instancias[i])):
			arst = arst + 1

	print(str(fab) + " " + str(cli) + " " + str(arst))
	for i in range(0,len(instancias)):
		for j in range(0,len(instancias[i])):
			print(str(instancias[i][j][0]) + " " + str(instancias[i][j][1]))


if __name__ == '__main__':
    componentes()