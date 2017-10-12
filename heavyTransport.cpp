#include <vector>
#include <queue>
#include "heavyTransport.h"
#include "graph.h"
#include "edge.h"
#include <iostream>




/********************************************/
/******** Basado en la idea de Pato *********/
/********************************************/

/*  PLOT TWIST: el grafo que nos pasan por parametro PUEDE
 *  no ser conexto. Khee?? Si, en ninguna parte del enunciado
 *  dice que el grafo es conexo entonces no podemos aplicar
 *  prim asi nomas. Pero para no todo esta perdido... El algoritmo
 *  funciona perfecto si el grafo es conexo.
 *
 *  Solucion: la solucion se puede pensar de la siguiente manera
 *  1) SPLIT: dividimos el grafo en componentes conexas
 *  2) APPLY: aplicamos el algoritmo a cada componente conexas
 *  3) COMBINE: combinamos las componentes
 *
 *  Complejidad: la complejidad va a ser la suma de lo que nos cuesta
 *  correr el algoritmo original en cada una de las componentes conexas que
 *  tendria que dar en total O(|V|^2)
 */



/*
NOTE: La version original falla con este caso:

2 3 6
1 3 3
1 4 3
3 4 1
2 5 1
4 5 6
1 2 1
0

La solucion que propone contiene una ruta entre las fabricas 1 y 2

SOLUCIONADO!

*/

/*****************************************************************************/

HeavyTransport::HeavyTransport(unsigned int factories, unsigned int clients){
  _factories = factories;
  _clients = clients;
}


unsigned int HeavyTransport::getFactories(){
	return _factories;
}


unsigned int HeavyTransport::getClients(){
	return _clients;
}


void HeavyTransport::addRoad(unsigned int fc1, unsigned int fc2, unsigned int cost){
  Edge e;
  e.vertexA = fc1 - 1; // Las fabricas y clientes se ingresan numerados del 1 a factories+clients
  e.vertexB = fc2 - 1;
  e.weight = cost;
  _roadsList.push_back(e);
}


vector<Edge> HeavyTransport::PrimMod(const Graph& G, vector<vector<int> >& adjacencyList) const{
  /* Version de algoritmo de prim modificada en la cual al inicio
   * los nodos que corresponden a las fabricas se marcan como
   * visitados. El algoritmo devuelve una lista de ejes que se
   * corresponden con los ejes usados en la solucion optima.
   */


	// Marcamos las fabricas como visitadas
	vector<bool> visited(G.getVertexCount(),false);
	set<Edge> edges;

	for (unsigned int i = 0; i < _factories; ++i){
		visited[i] = true;
		for (auto it = adjacencyList[i].begin(); it != adjacencyList[i].end() ; ++it){
			if((unsigned int)*it >= _factories) {
				Edge e(i,*it,G.weight(i,*it));
				edges.insert(e);
			}
		}
	}

	vector<Edge> S;

	while(!edges.empty()){
		Edge e = *(edges.begin());
		edges.erase(e);
		if (!visited[e.vertexA] || !visited[e.vertexB] ){
			int new_vertex = !visited[e.vertexA] ? e.vertexA : e.vertexB;
			visited[new_vertex] = true;
			S.push_back(e);
			for (auto it = adjacencyList[new_vertex].begin(); it != adjacencyList[new_vertex].end() ; ++it){
				if(!visited[*it]) {
					Edge e(new_vertex,*it,G.weight(new_vertex,*it));
					edges.insert(e);
				}
			}
		}
	}

	return S;

}

// Solo para arboles y no arboles
vector<vector<int> > HeavyTransport::getAdjacencyList(const Graph& G) const{
  // Devuelve la lista de adyacencia para el grafo G.
  vector<vector<int> > adjacencyList(G.getVertexCount());
  for(size_t i = 0; i < G.getVertexCount(); i++){ //O(parents.size())
    for (size_t j = 0; j < G.getVertexCount(); j++){
    if(G.adjacent(i,j))
    	adjacencyList[i].push_back(j);
    }
  }
  return adjacencyList;
}


Graph HeavyTransport::getOptimalSolution() const {
	Graph hT(_factories + _clients, _roadsList);
	vector<vector<int> > adjacencyList = getAdjacencyList(hT);
	vector<Edge> S = PrimMod(hT,adjacencyList);
	Graph Sol(hT.getVertexCount(),S);
	return Sol;
}
