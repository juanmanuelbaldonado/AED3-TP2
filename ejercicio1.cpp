#include "graph.h"
#include "solver.h"
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <tuple>
using namespace std;

int main() {

  vector<vector<vector<int > > > instances;

  unsigned int N,edgeWeight;
  string row;

  cin >> N;
  while(N != 0){
      N++;
      vector<vector<int > > weights(N, vector<int>(N,0));
      cin.ignore();
      for (size_t i = 1; i < N ; i++) {
        getline(std::cin,row);
        stringstream stream(row);
        for (size_t j = 0; j < i; j++) {
          stream >> edgeWeight;
          weights[j][i] =  edgeWeight;
        }
      }
      instances.push_back(weights);
      // Siguiente instancia...
      std::cin >> N;
  }

  for (size_t i = 0; i < instances.size(); i++) {

    vector<vector<int > > weights = instances[i];

    tuple<int,int,vector<int> > res = Solver(weights);
    vector<int > path = get<2>(res);

    cout << get<0>(res) << " " << get<1>(res) << " ";

    for (size_t i = 0; i < path.size(); i++) {
      cout << path[i];
      if (i == path.size()-1) cout << endl;
      else cout << " ";
    }
  }


  return 0;
}
