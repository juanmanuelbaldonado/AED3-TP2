#include "graph.h"
#include "edge.h"

#include <vector>
#include <set>
#include <iostream>
#include <limits>


using namespace std;
#define INFINITY numeric_limits<int>::max()


Graph::Graph(unsigned int vertexCount, vector<Edge>& edges){
  // Constructor, 
  num_v = vertexCount;
  adjacency_matrix = vector<vector<bool > >(vertexCount, vector<bool>(vertexCount, false));
  weights = vector<vector<int > >(vertexCount, vector<int>(vertexCount, 0));

  // Las matrices son simetricas
  for(unsigned int i = 0; i < edges.size(); i++){
    adjacency_matrix[edges[i].vertexA][edges[i].vertexB] = true;
    adjacency_matrix[edges[i].vertexB][edges[i].vertexA] = true;
    weights[edges[i].vertexA][edges[i].vertexB] = edges[i].weight;
    weights[edges[i].vertexB][edges[i].vertexA] = edges[i].weight;
  }
}


Graph::Graph(vector<vector<bool > > M, vector<vector<int > > W ){
  /* Inicializa un objeto del tipo Graph donde M se corresponde con
   * la matriz de adyacencia y W con los pesos de las aristas.
   */

  num_v = M.size();
  adjacency_matrix = M;
  weights = W;
}

bool Graph::adjacent(unsigned int v, unsigned int w){
  return adjacency_matrix[v][w];
}



pair<vector<int >, vector<int> > Graph::Dijkstra(unsigned int v){
  /* Implementacion del algoritmo de Dijkstra para obtener los
   * caminos minimos del grafo. Devuelve un par < pi , pred > donde
   *  -> pi[j] = "Camino de longitud minima entre v y j. "
   *  -> pred[j] = "Predecesor de j en su camino minimo."
   */

  vector<int> S(num_v,0);
  vector<int> pi(num_v,0);
  vector<int> pred(num_v,0);
  S[v] = 1;
  pi[v] = 0;


  for (size_t u = 0; u < num_v; u++) {
    if(v!= u){
      pi[u] = adjacent(v,u) ? weights[v][u] : INFINITY;
      pred[u] = adjacent(v,u) ? v : INFINITY;
    }
  }

  for (size_t k = 0; k < num_v; k++) {

    int w;
    int min = INFINITY;

    for (size_t j = 0; j < num_v; j++) {
      if( S[j] == 0  && pi[j] < min ){
        w = j;
        min = pi[j];
      }
    }
    /* S := S u {w} */
    S[w] = 1;

    for (size_t u = 0; u < num_v; u++) {
      if ( S[u] == 0  && adjacent(w,u) && (pi[u] > pi[w] + weights[w][u]) ){
        pi[u] = pi[w] + weights[w][u];
        pred[u] = w;
      }
    }
  }

  return make_pair(pi,pred);
}

unsigned int Graph::pathSum(const vector<int >& path){
  /* Devuelve la sumatoria de los pesos en el camino pasado por parametro. */

  unsigned int sum = 0;
  unsigned int prev = 0;
  for (size_t i = 1; i < path.size(); i++) {
    if(path[i] == 1){
      sum += weights[prev][i];
      prev = i;
    }
  }
  return sum;
}


vector<int> Graph::prim(){
  vector<bool> visited(num_v, false);
  vector<int> distance(num_v, INFINITY);
  vector<int> parent(num_v, INFINITY);

  // Se toma arbitrariamente el nodo 0 como nodo inicial
  unsigned int vertex = 0;
  for(unsigned int i = 1; i < num_v; i++){
    if(adjacency_matrix[vertex][i]){
      distance[i] = weights[vertex][i];
      parent[i] = vertex;
    }
  }

  distance[vertex] = 0;
  visited[vertex] = true;

  // En num_v iteraciones se visitan todos los nodos
  for(unsigned int i = 0; i < num_v; i++){
    // Se busca el nodo de menor distancia para agregar que no fue visitado aun
    vertex = INFINITY;
    for(unsigned int j = 0; j < num_v; j++){
      if(!visited[j] && distance[j] < vertex){
        vertex = distance[j];
      }
    }

    visited[vertex] = true;
    // Se buscan los sucesores de vertex
    for(unsigned int j = 0; j < num_v; j++){
      if(!visited[j] && adjacency_matrix[vertex][j] && distance[j] > weights[vertex][j]){
        distance[j] = weights[vertex][j];
        parent[j] = vertex;
      }
    }
  }

  return parent;
}