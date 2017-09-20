#include "graph.h"
#include <iostream>
#include <stdlib.h>
#include <sstream>

using namespace std;

int main() {
  /* Inicializamos matriz de adyacencia */
  int v,n;
  cin >> v;
  vector<vector<bool > > M(v, vector<bool >(v,0)) ;
  vector<vector<int > > weights(v, vector<int>(v,0));

  string row;
  cin.ignore();



  for (size_t i = 0; i < v; i++) {
    getline(std::cin,row);
    stringstream stream(row);
    for (size_t j = 0; j < v; j++) {
      stream >> n;
      M[i][j] = i==j ? 1 :  n;
    }
  }

    /* Inicializamos pesos */

  for (size_t i = 0; i < v; i++) {
    getline(std::cin,row);
    stringstream stream(row);
    for (size_t j = 0; j < v; j++) {
      stream >> n;
      weights[i][j] = i==j ? 0 : n;
    }
  }

  Graph g = Graph(M,weights);
  pair< vector<int >, vector<int> > res = g.Dijkstra(0);
  cout << "RES: " << "{ ";
  for (size_t i = 0; i < res.first.size(); i++) {
    cout << res.first[i] << " ";
  }
  cout << "}" << endl;

  cout << "RES: " << "{ ";
  for (size_t i = 0; i < res.second.size(); i++) {
    cout << res.second[i] << " ";
  }
  cout << "}" << endl;



  return 0;

}
