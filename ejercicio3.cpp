#include "graph.h"
#include "edge.h"

#include <iostream>
#include <string>
#include <vector>

#include <queue>

std::vector<int> bfsTreeDistance(const Graph &tree, unsigned int startVertex){
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

bool getNextInstanceData(unsigned int &factories, unsigned int &clients, unsigned int &roads){
    std::cin >> factories;
    if(factories == 0){
        return false;
    }
    std::cin >> clients;
    std::cin >> roads;
    return true;
}

int main(){
    std::vector<Graph> heavyTransportList;

    unsigned int factories;
    unsigned int clients;
    unsigned int roads;

    // La entrada concluye con una lı́nea comenzada por 0, la cual no debe procesarse.
    while(getNextInstanceData(factories, clients, roads)){
        vector<Edge> roadsList;

        for(unsigned int i = 0; i < roads; i++){
            Edge e;
            std::cin >> e.vertexA;
            std::cin >> e.vertexB;
            std::cin >> e.weight;
            e.vertexA--; // Las fabricas y clientes se ingresan numerados del 1 a factories+clients
            e.vertexB--;
            roadsList.push_back(e);
        }

        Graph heavyTransport(factories + clients, roadsList);

        vector<int> parents = heavyTransport.prim();
        vector<Edge> roadsListMST;

        // Se crea la lista de ejes a partir del resultado devuelto por Prim
        for(unsigned int i = 1; i < factories + clients; i++){
            Edge e;
            e.vertexA = i;
            e.vertexB = parents[i];
            e.weight = heavyTransport.weight(e.vertexA, e.vertexB);
            roadsListMST.push_back(e);
        }

        // Grafo/Arbol generador minimo
        Graph heavyTransportMST(factories + clients, roadsList);

        // Distancia de cada nodo (cliente o fabrica) a cada fabrica
        vector<vector<int> > distancesToFactory(factories);

        for(unsigned int i = 0; i < factories; i++){
            distancesToFactory[i] = bfsTreeDistance(heavyTransportMST, i);
        }

        // Fabrica mas cercana a cada cliente
        vector<int> closestFactoryToEachClient(clients);

        for(unsigned int c = 0; c < clients; c++){
            int closestFactory = distancesToFactory[0][c];
            for(unsigned int f = 1; f < factories; f++){
                if(distancesToFactory[f][c] < closestFactory){
                    closestFactory = distancesToFactory[f][c];
                }
            }
            closestFactoryToEachClient[c] = closestFactory;
        }

        // Modificamos el grafo/arbol eliminando las aristas/rutas innecesarias
        for(unsigned int i = 0; i < factories + clients; i++){
            for(unsigned int j = 0; j < factories + clients; j++){
                if(closestFactoryToEachClient[i] != closestFactoryToEachClient[j]){
                    heavyTransportMST.setAdjacency(i, j, false);
                }
            }
        }

        heavyTransportList.push_back(heavyTransportMST);
    }

    for(unsigned int i = 0; i < heavyTransportList.size(); i++){

        int solutionCost = heavyTransportList[i].weightSum();
        int roadsCount = heavyTransportList[i].edgeCount();;

        std::cout << solutionCost << " " << roadsCount << " ";

        for(unsigned int i = 0; i < factories + clients; i++){
            for(unsigned int j = 0; j < i; j++){
              if(heavyTransportList[i].adjacent(i, j)){
                std::cout << i << " " << j << " ";
              }
            }
          }

        std::cout << std::endl;
    }

    return 0;
}