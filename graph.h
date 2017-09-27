#ifndef GRAPH_H

#include "edge.h"

#include <vector>
#include <utility>
#include <set>
using namespace std;


class Graph{
private:
  unsigned int num_v; // cantidad de vertices de vertices
  vector<vector<bool > > adjacency_matrix ;
  vector<vector<int > > weights;

public:
  Graph(unsigned int vertexCount, const vector<Edge>& edges);
  Graph(vector<vector<bool > > M, vector<vector<int > > W );
  unsigned int getVertexCount() const;
  bool adjacent(unsigned int v, unsigned int w) const;
  void setAdjacency(unsigned int v, unsigned int w, bool adjacency);
  int weight(unsigned int v, unsigned int w) const;
  int weightSum() const;
  int edgeCount() const;
  pair<vector<int >,vector<int >> Dijkstra(unsigned int v);
  unsigned int pathSum(const vector<int >& path);

  vector<int> prim() const;
};

#define GRAPH_H
#endif
