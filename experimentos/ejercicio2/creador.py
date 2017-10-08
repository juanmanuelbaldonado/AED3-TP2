#!/usr/bin/python

import random
import math


def max(nodos):
	aristas = []
	for i in range(1,nodos):
		for j in range(i+1,nodos+1):
			aristas.append((i,j))
	
	pesos = []
	maxN = (nodos*(nodos-1))/2
	for i in range(1, int(maxN)+1):
		pesos.append(i)
	
	instancia = []
	for i in range(1,int(maxN)+1):
		if not (len(aristas) == 0):
			secure_random = random.SystemRandom()
			arista = secure_random.choice(aristas)
			aristas.remove(arista)
			secure_random2 = random.SystemRandom()
			peso = secure_random2.choice(pesos)
			instancia.append((arista,peso))
	
	print(str(nodos) + ' ' + str(len(instancia)-1))
	for i in range(1,len(instancia)):
		print(str(instancia[i][0][0]) + ' ' + str(instancia[i][0][1]) + ' ' + str(instancia[i][1]))

def med(nodos):
	aristas = []
	for i in range(1,nodos):
		auxiliar = []
		for j in range(i+1,nodos+1):
			auxiliar.append((i,j))
		aristas.append(auxiliar)
	
	pesos = []
	medN = ((nodos*(nodos-1))/2)/2
	for i in range(1, int(medN)+1):
		pesos.append(i)
	
	instancia = []
	for i in range(1,int(medN)+1):
		if i == 1:
			arista = aristas[0][0]
			aristas[0].remove(arista)
			secure_random2 = random.SystemRandom()
			peso = secure_random2.choice(pesos)
			instancia.append((arista,peso))
		if not (len(aristas) == 0):
			if i < nodos:
				arista = aristas[i-1][0]
				aristas[i-1].remove(arista)
				secure_random2 = random.SystemRandom()
				peso = secure_random2.choice(pesos)
				instancia.append((arista,peso))
			else:
				secure_random = random.SystemRandom()
				aux = secure_random.choice(aristas[0:len(aristas)-2])
				arista = secure_random.choice(aux)
				secure_random2 = random.SystemRandom()
				peso = secure_random2.choice(pesos)
				instancia.append((arista,peso))
	
	print(str(nodos) + ' ' + str(len(instancia)-1))
	for i in range(1,len(instancia)):
		print(str(instancia[i][0][0]) + ' ' + str(instancia[i][0][1]) + ' ' + str(instancia[i][1]))

def min(nodos):
	aristas = []
	for i in range(1,nodos):
		auxiliar = []
		for j in range(i+1,nodos+1):
			auxiliar.append((i,j))
		aristas.append(auxiliar)
	
	pesos = []
	for i in range(1, nodos+2):
		pesos.append(i)
	instancia = []
	for i in range(1,nodos+1):
		if i == 1:
			arista = aristas[0][0]
			aristas[0].remove(arista)
			secure_random2 = random.SystemRandom()
			peso = secure_random2.choice(pesos)
			instancia.append((arista,peso))
		if not (len(aristas) == 0):
			if i < nodos:
				arista = aristas[i-1][0]
				aristas[i-1].remove(arista)
				secure_random2 = random.SystemRandom()
				peso = secure_random2.choice(pesos)
				instancia.append((arista,peso))
			else:
				secure_random = random.SystemRandom()
				aux = secure_random.choice(aristas[0:len(aristas)-2])
				arista = secure_random.choice(aux)
				secure_random2 = random.SystemRandom()
				peso = secure_random2.choice(pesos)
				instancia.append((arista,peso))
	
	print(str(nodos) + ' ' + str(len(instancia)-1))
	for i in range(1,len(instancia)):
		print(str(instancia[i][0][0]) + ' ' + str(instancia[i][0][1]) + ' ' + str(instancia[i][1]))

def aristas(nodos, aristasTot):
	aristas = []
	for i in range(1,nodos):
		for j in range(i+1,nodos+1):
			aristas.append((i,j))
	
	pesos = []
	for i in range(1, nodos+1):
		pesos.append(i)
	
	instancia = []
	for i in range(1,aristasTot+1):
		if not (len(aristas) == 0):
			secure_random = random.SystemRandom()
			arista = secure_random.choice(aristas)
			aristas.remove(arista)
			secure_random2 = random.SystemRandom()
			peso = secure_random2.choice(pesos)
			instancia.append((arista,peso))
	
	print(str(nodos) + ' ' + str(len(instancia)-1))
	for i in range(1,len(instancia)):
		print(str(instancia[i][0][0]) + ' ' + str(instancia[i][0][1]) + ' ' + str(instancia[i][1]))


def selector(tipo, nodos, aristasTot):
	if(tipo == "aristas"):
		for i in range(4,aristasTot):
			aristas(nodos, i)
	elif(tipo == "max"):
		for i in range(4, nodos):
			max(i)
	elif(tipo == "med"):
		for i in range(4, nodos):
			med(i)
	elif(tipo == "min"):
		for i in range(4, nodos):
			min(i)
	print('0')

if __name__ == '__main__':
    selector()