#!/usr/bin/python

import random
import math

def creadorGrafo(nodos, aristas):

	nodosRestantes = []
	for i in range(0,nodos):
		nodosRestantes.append(i+1)

	aristasRestantes = []
	for i in range(0,nodos-1):
		for j in range(i+1,nodos):
			aristasRestantes.append((i+1,j+1))

	nodosElegidos = []
	grafo = []
	#Me genero el grafo conexo inicial
	for i in range(0,nodos-1):
		#Caso base: cuando el grafo está vacio
		if i == 0:
			secure_random = random.SystemRandom()

			nodo1 = secure_random.choice(nodosRestantes)
			nodosRestantes.remove(nodo1)
			nodo2 = secure_random.choice(nodosRestantes)
			nodosRestantes.remove(nodo2)
			
			nodosElegidos.append(nodo1)
			nodosElegidos.append(nodo2)
			grafo.append((nodo1,nodo2))
	
			if (nodo1,nodo2) in aristasRestantes:
				aristasRestantes.remove((nodo1,nodo2))
			else:
				aristasRestantes.remove((nodo2,nodo1))

		#El grafo ya no está vacio
		else:

			secure_random = random.SystemRandom()

			nodoNuevo = secure_random.choice(nodosRestantes)
			nodosRestantes.remove(nodoNuevo)
			nodoOriginal = secure_random.choice(nodosElegidos)

			nodosElegidos.append(nodoNuevo)
			grafo.append((nodoOriginal,nodoNuevo))

			if (nodoOriginal,nodoNuevo) in aristasRestantes:
				aristasRestantes.remove((nodoOriginal,nodoNuevo))
			else:
				aristasRestantes.remove((nodoNuevo,nodoOriginal))


	#Lleno el resto del grafo hasta cantidad de aristas
	for i in range(0,aristas-(nodos-1)):
		if len(aristasRestantes) != 0:
			secure_random = random.SystemRandom()
			arista = secure_random.choice(aristasRestantes)
			aristasRestantes.remove(arista)

			grafo.append(arista)
		else:
			break

	return grafo


def asignarPesos(grafo):

	pesos = []
	for i in range(0,len(grafo)*2):
		pesos.append(i)

	grafoPesado = []
	for i in range(0,len(grafo)):
		secure_random = random.SystemRandom()
		peso = secure_random.choice(pesos)

		grafoPesado.append((grafo[i],peso))

	return grafoPesado


def imprimirGrafoPesado(nodos,aristas,grafoPesado):

	print(str(nodos) + " " + str(aristas))

	for i in range(0,len(grafoPesado)):
		print(str(grafoPesado[i][0][0]) + " " + str(grafoPesado[i][0][1]) + " " + str(grafoPesado[i][1]))


def creadorInstancias(nodos,aristas,step,variacion):

	instancias = []
	if variacion == "nodos":

		for i in range(2,nodos+1,step):
			if aristas == 1:
				#caso max
				arst = int((i*(i-1))/2)
			elif aristas == 0:
				#caso med
				arst = int(((i*(i-1))/2)/2)
			elif aristas == -1:
				#caso min
				arst = i
			instancias.append((i,arst,asignarPesos(creadorGrafo(i,arst))))

	elif variacion == "aristas":

		for i in range(0,aristas,step):
			instancias.append((nodos,i+nodos,asignarPesos(creadorGrafo(nodos,i+nodos))))

	return instancias

def imprimirInstancias(instancias):

	for i in range(0,len(instancias)):
		imprimirGrafoPesado(instancias[i][0],instancias[i][1],instancias[i][2])
	print('0')




if __name__ == '__main__':
	creadorInstancias()
    imprimirInstancias()
