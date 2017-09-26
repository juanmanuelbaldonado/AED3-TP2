#include <vector>
#include "heavyTransport.h"
#include "graph.h"
#include "edge.h"

heavyTransport::heavyTransport(unsigned int factories, unsigned int clients){
    _factories = factories;
    _clients = clients;
}


void heavyTransport::addRoad(unsigned int fc1, unsigned int fc2, unsigned int cost){
    Edge e;
    e.vertexA = fc1 - 1; // Las fabricas y clientes se ingresan numerados del 1 a factories+clients
    e.vertexB = fc2 - 1;
    e.weight = cost;
    _roadsList.push_back(e);
}


Graph heavyTransport::getOptimalSolution() const {
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
        int closestFactory = distancesToFactory[0][c];
        for(unsigned int f = 1; f < _factories; f++){
            if(distancesToFactory[f][c] < closestFactory){
                closestFactory = distancesToFactory[f][c];
            }
        }
        closestFactoryToEachClient[c] = closestFactory;
    }

    // Modificamos el grafo/arbol eliminando las aristas/rutas innecesarias
    for(unsigned int i = 0; i < _factories + _clients; i++){
        for(unsigned int j = 0; j < _factories + _clients; j++){
            if(closestFactoryToEachClient[i] != closestFactoryToEachClient[j]){
                hTMST.setAdjacency(i, j, false);
            }
        }
    }

    return hTMST;
}


std::vector<int> heavyTransport::bfsTreeDistance(const Graph &tree, unsigned int startVertex) const {
    unsigned int vertex;
    std::queue<unsigned int> vertexQueue;
    std::vector<int> distaces(tree.getVertexCount(), 0);

    vertexQueue.push(startVertex);

    while(!vertexQueue.empty()){
        vertex = vertexQueue.front();
        vertexQueue.pop();
        for(unsigned int i = 0; i < tree.getVertexCount(); i++){
            if(tree.adjacent(vertex, i)){
                distaces[i] = distaces[vertex] + tree.weight(vertex, i);
                vertexQueue.push(vertex);
            }
        }
    }

    return distaces;
}