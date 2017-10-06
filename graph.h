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

  class VertexDistance{
    private:
      unsigned int _vertexNumber;
      int _distance;

    public:
      VertexDistance(unsigned int vertexNumber, int distance);
      unsigned int getVertexNumber() const;
      int getDistance() const;
      bool operator<(const VertexDistance& b) const;
      bool operator==(const VertexDistance& b) const;
  };

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
  vector<int> primWithQueue() const;

  //int farthestNode(vector<vector<int> >& T, int n_0);
  //int networkCost(Graph& network,vector<int>& parents);
  //vector<Edge> getLinks(Graph& network,vector<int>& parents);
  //bool search(vector<vector<int> >& T, vector<int>& visited, vector<int>& path,unsigned int current, unsigned int target);
  //vector<int> makePath(vector<vector<int> >&  T, unsigned int root,unsigned int target);
  //int getMaster(vector<int>& parents);
};

#define GRAPH_H
#endif
