#include "graph.h"
#include "edge.h"
#include "heavyTransport.h"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include <chrono>
#define now std::chrono::high_resolution_clock::now

bool getNextInstanceData(unsigned int &factories, unsigned int &clients, unsigned int &roads){
    std::string instanceData;
    std::getline(std::cin, instanceData);
    stringstream instanceDataStream(instanceData);
    instanceDataStream >> factories;

    if(factories == 0){
        return false;
    }

    instanceDataStream >> clients;
    instanceDataStream >> roads;
    return true;
}

int main(int argc, char** argv){
    int tiempos = 0;
    if(argc > 1){tiempos = std::atoi(argv[1]);}

    std::vector<HeavyTransport> heavyTransportList;

    unsigned int factories;
    unsigned int clients;
    unsigned int roads;

    // La entrada concluye con una lı́nea comenzada por 0, la cual no debe procesarse.
    while(getNextInstanceData(factories, clients, roads)){
        HeavyTransport heavyTransport(factories, clients);

        for(unsigned int i = 0; i < roads; i++){
            std::string road;
            std::getline(std::cin, road);
            stringstream roadStream(road);
            unsigned int fc1;
            unsigned int fc2;
            unsigned int cost;
            roadStream >> fc1;
            roadStream >> fc2;
            roadStream >> cost;
            heavyTransport.addRoad(fc1, fc2, cost);
        }

        heavyTransportList.push_back(heavyTransport);
    }


    if(tiempos){std::cout << "fab,cli,tiempo" << std::endl;}

    // Se calcula la solucion para cada instancia del problema
    std::vector<Graph> heavyTransportSolutionList;
    for(size_t i = 0; i < heavyTransportList.size(); i++){

        std::chrono::high_resolution_clock::time_point t1;
        std::chrono::high_resolution_clock::time_point t2;
        std::chrono::duration<double> time_span;

        unsigned int fabs = heavyTransportList[i].getFactories();
        unsigned int clis = heavyTransportList[i].getClients();

        t1 = now();
        heavyTransportSolutionList.push_back(heavyTransportList[i].getOptimalSolution());
        t2 = now();

        time_span = std::chrono::duration_cast<std::chrono::duration<double> >(t2-t1);

        if(tiempos){
            std::cout << fabs << "," << clis << "," << time_span.count() << std::endl;
        }
    }

    // Output
    if(tiempos != 1) {
        for(size_t i = 0; i < heavyTransportSolutionList.size(); i++){
    
            int solutionCost = heavyTransportSolutionList[i].weightSum();
            int roadsCount = heavyTransportSolutionList[i].edgeCount();;
    
            std::cout << solutionCost << " " << roadsCount << " ";
    
            for(size_t j = 0; j < heavyTransportSolutionList[i].getVertexCount(); j++){
                for(size_t k = j+1; k < heavyTransportSolutionList[i].getVertexCount(); k++){
                  if(heavyTransportSolutionList[i].adjacent(j, k)){
                    // Las fabricas y clientes se guardan numerados del 0 a factories+clients-1
                    // pero se ingresan numerados del 1 a factories+clients
                    std::cout << j+1 << " " << k+1 << " ";
                  }
                }
              }
    
            std::cout << std::endl;
        }
    }

    return 0;
}
