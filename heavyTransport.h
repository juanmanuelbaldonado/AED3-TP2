#ifndef HEAVYTRANSPORT_H
#define HEAVYTRANSPORT_H

#include "graph.h"
#include <vector>

class HeavyTransport{
    public:
        HeavyTransport(unsigned int factories, unsigned int clients);
        void addRoad(unsigned int fc1, unsigned int fc2, unsigned int cost);
        vector<Edge> Kruskal(const Graph& G, vector<vector<int> >& incidenceList) const;
        Graph getOptimalSolution() const;
        vector<vector<int> > getInsidenceList(const Graph& G) const;
        Graph getOptimalSolution(const Graph& G) const;

    private:
        unsigned int _factories;
        unsigned int _clients;
        std::vector<Edge> _roadsList;

};

pair<int,int> getFC(vector<int>& component, unsigned int originalF);


#endif
