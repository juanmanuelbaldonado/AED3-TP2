#include "graph.h"
#include "edge.h"

#include <iostream>
#include <string>
#include <vector>

int main(){
    std::vector<Graph> networks;

    unsigned int serverCount;
    unsigned int links;

    // La entrada concluye con una lı́nea comenzada por 0, la cual no debe procesarse.
    std::cin >> serverCount;
    while(serverCount != 0){
        std::cin >> links;
        vector<Edge> linksList;

        for(unsigned int i = 0; i < links; i++){
            Edge e;
            std::cin >> e.vertexA;
            std::cin >> e.vertexB;
            std::cin >> e.weight;
            e.vertexA--; // Los servidores se ingredan numerados del 1 a serverCount
            e.vertexB--;
            linksList.push_back(e);
        }

        networks.push_back(Graph(serverCount, linksList));

        // Siguiente instancia...
        std::cin >> serverCount;
    }

    for(unsigned int i = 0; i < networks.size(); i++){
        vector<int> parents = networks[i].prim();
        vector<Edge> linksList;

        int solutionCost;
        int masterServer;
        int linksCount;

        std::cout << solutionCost << " " << masterServer << " " << linksCount << " ";

        // Luego de calcular el arbol generador minimo, cada nodo tiene un solo padre
        for(unsigned int i = 0; i < parents.size(); i++){
            std::cout << i << " " << parents[i] << " ";
        }


        // RECETA PARA EL CAMINO MAXIMO (no pregunten):
        // 1: dfs de un nodo random (funcion farthestNode (esta implementada))
        // 2: tiras dfs del nodo que devuelve dfs
        // 3: ???
        // 4: Profit
        // 5: tu camino maximo es el camino entre el nodo que devolvio el primer dfs y el segundo
        
        // Tomar el elemnto en la posicion tam(camino)/2 parte entera inferior o algo asi

        std::cout << std::endl;
    }
    
    return 0;
}