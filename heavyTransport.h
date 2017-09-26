#ifndef HEAVYTRANSPORT_H
#define HEAVYTRANSPORT_H

#include "graph.h"
#include <vector>

class heavyTransport{
    public:
        heavyTransport(unsigned int factories, unsigned int clients);
        void addRoad(unsigned int fc1, unsigned int fc2, unsigned int cost);
        Graph getOptimalSolution() const;

    private:
        std::vector<int> bfsTreeDistance(const Graph &tree, unsigned int startVertex) const;

        unsigned int _factories;
        unsigned int _clients;
        std::vector<Edge> _roadsList;
};

#endif

