#ifndef HEAVYTRANSPORT_H
#define HEAVYTRANSPORT_H

#include "graph.h"
#include <vector>

class HeavyTransport{
    public:
        HeavyTransport(unsigned int factories, unsigned int clients);
        void addRoad(unsigned int fc1, unsigned int fc2, unsigned int cost);
        Graph getOptimalSolution() const;
        Graph applyToComponents();


    private:
        std::vector<int> bfsTreeDistance(const Graph &tree, unsigned int startVertex) const;

        unsigned int _factories;
        unsigned int _clients;
        std::vector<Edge> _roadsList;

};

pair<int,int> getFC(vector<int>& component, unsigned int originalF);


#endif
