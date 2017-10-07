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



Graph HeavyTransport::applyToComponents(){
  Graph hT(_factories + _clients, _roadsList); //O(|V|^2)

  pair<int, vector<int> > components = hT.labelComponents(); // O(|V|^2)

  vector<vector<int> > componentsList(components.first);
  for (size_t i = 0; i < components.second.size(); i++) { // O(|V|)
    componentsList[components.second[i]].push_back(i);
  }



  for (size_t i = 0; i < componentsList.size(); i++) {
    /* Para cada componente conexa hacemos lo siguiente*/

    unsigned int cSize = componentsList[i].size();
    pair< int, int> component_fc; // = getFC(componentsList[i],_factories);
    for (size_t j = 0; j < cSize; j++) {
      // NOTE: quiza va un component.size() - i - 1
      if(componentsList[i][j] >= _factories){
        component_fc =  make_pair(j, cSize - j);
        break;
      }
    }



    HeavyTransport cc(component_fc.first, component_fc.second);

    for (size_t v = 0; v < cSize; v++) {
      for (size_t w = v + 1; w < cSize; w++) {
        if(hT.adjacent(componentsList[i][v],componentsList[i][w])){
          cc.addRoad(v+1, w+1, hT.weight(componentsList[i][v],componentsList[i][w]) );
        }
      }
    }




    // APPLY : aplicamos el algoritmo a la componente conexa
    Graph cc_sol = cc.getOptimalSolution();//O(|cSize|^2)


    // COMBINE: actualizamos el grafo original con los resultados
    for (size_t v = 0; v < cSize; v++) {
      for (size_t w = 0; w < cSize; w++) {
          int original_v = componentsList[i][v];
          int original_w = componentsList[i][w];
          if (cc_sol.adjacent(v,w)) hT.setAdjacency(original_v,original_w,true);
          else hT.setAdjacency(original_v,original_w,false);
      }
    }
  }

  return hT;
}



/*****************************************************************************/

HeavyTransport::HeavyTransport(unsigned int factories, unsigned int clients){
  _factories = factories;
  _clients = clients;
}


void HeavyTransport::addRoad(unsigned int fc1, unsigned int fc2, unsigned int cost){
  Edge e;
  e.vertexA = fc1 - 1; // Las fabricas y clientes se ingresan numerados del 1 a factories+clients
  e.vertexB = fc2 - 1;
  e.weight = cost;
  _roadsList.push_back(e);
}


Graph HeavyTransport::getOptimalSolution() const {
    Graph hT(_factories + _clients, _roadsList);

    vector<int> parents = hT.prim();
    vector<Edge> roadsListMST;

    // Se crea la lista de ejes a partir del resultado devuelto por Prim
    for(unsigned int i = 1; i < _factories + _clients; i++){
        Edge e;
        e.vertexA = i;
        e.vertexB = parents[i];
        e.weight = hT.weight(e.vertexA, e.vertexB);
        roadsListMST.push_back(e);
    }

    // Grafo/Arbol generador minimo
    Graph hTMST(_factories + _clients, roadsListMST);

    // Distancia de cada nodo (cliente o fabrica) a cada fabrica
    vector<vector<int> > distancesToFactory(_factories);

    for(unsigned int i = 0; i < _factories; i++){
        distancesToFactory[i] = bfsTreeDistance(hTMST, i);
    }

    // Fabrica mas cercana a cada cliente
    vector<int> closestFactoryToEachClient(_clients);

    for(unsigned int c = 0; c < _clients; c++){
        int closestFactory = 0;
        for(unsigned int f = 1; f < _factories; f++){
            if(distancesToFactory[f][_factories + c] < closestFactory){
                closestFactory = f;
            }
        }
        closestFactoryToEachClient[c] = closestFactory;
    }

    // Modificamos el grafo/arbol eliminando las aristas/rutas innecesarias entre fábricas
    for(unsigned int i = 0; i < _factories; i++){
        for(unsigned int j = 0; j < _factories; j++){
            hTMST.setAdjacency(i, j, false);
        }
    }

    // Modificamos el grafo/arbol eliminando las aristas/rutas innecesarias entre clientes
    for(unsigned int i = 0; i < _clients; i++){
        for(unsigned int j = 0; j < _clients; j++){
            if(closestFactoryToEachClient[i] != closestFactoryToEachClient[j]){
                hTMST.setAdjacency(_factories + i, _factories + j, false);
            }
        }
    }

    // Modificamos el grafo/arbol eliminando las aristas/rutas innecesarias entre un cliente y una fábrica
    for(unsigned int i = 0; i < _factories; i++){
        for(unsigned int j = 0; j < _clients; j++){
            if((int)i != closestFactoryToEachClient[j]){
                hTMST.setAdjacency(i, _clients + j, false);
            }
        }
    }

    return hTMST;
}


std::vector<int> HeavyTransport::bfsTreeDistance(const Graph &tree, unsigned int startVertex) const {
    unsigned int vertex;
    std::queue<unsigned int> vertexQueue;
    std::vector<int> distaces(tree.getVertexCount(), 0);
    std::vector<bool> visited(tree.getVertexCount(), false);

    vertexQueue.push(startVertex);
    visited[startVertex] = true;

    while(!vertexQueue.empty()){
        vertex = vertexQueue.front();
        vertexQueue.pop();
        for(unsigned int i = 0; i < tree.getVertexCount(); i++){
            if(!visited[i] && tree.adjacent(vertex, i)){
                distaces[i] = distaces[vertex] + tree.weight(vertex, i);
                vertexQueue.push(i);
                visited[i] = true;
            }
        }
    }

    return distaces;
}
