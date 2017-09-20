#ifndef GRAPH_H

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

  Graph(vector<vector<bool > > M, vector<vector<int > > W );
  bool adjacent(unsigned int v, unsigned int w);
  pair<vector<int >,vector<int >> Dijkstra(unsigned int v);
  unsigned int pathSum(const vector<int >& path);

};

#define GRAPH_H
#endif
