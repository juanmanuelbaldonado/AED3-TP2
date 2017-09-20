#include "graph.h"
#include "solver.h"
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <tuple>
using namespace std;

int main() {
  /* Inicializamos matriz de adyacencia */

  int n,pesoArista;
  cin >> n;
  n++;
  vector<vector<int > > weights(n, vector<int>(n,0));

  string row;
  cin.ignore();

  for (size_t i = 1; i < n ; i++) {
    getline(std::cin,row);
    stringstream stream(row);
    for (size_t j = 0; j < i; j++) {
      stream >> pesoArista;
      weights[j][i] =  pesoArista;
    }
  }


  /* uno harcodeado...
  vector<int > v0 = {0,1,9,9,9};
  vector<int > v1 = {0,0,1,9,9};
  vector<int > v2 = {0,0,0,1,9};
  vector<int > v3 = {0,0,0,0,1};
  vector<int > v4 = {0,0,0,0,0};
  vector<vector<int > > weights = {v0,v1,v2,v3,v4};


  for (size_t i = 0; i < 5; i++) {
    for (size_t j = 0; j <5; j++) {
      cout << weights[i][j] << " ";
    }
    cout << endl;
  }
  */
    /* Inicializamos pesos */

  tuple<int,int,vector<int> > res = Solver(weights);
  vector<int > path = get<2>(res);

  cout << get<0>(res) << " " << get<1>(res)-1 << " ";

  cout << "< ";
  for (size_t i = 1; i < path.size(); i++) {
    cout << path[i] << " ";
  }
  cout  << ">" << endl;




  return 0;

}
