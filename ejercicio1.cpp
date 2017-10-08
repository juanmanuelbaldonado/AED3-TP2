#include "graph.h"
#include "solver.h"
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <tuple>
#include <time.h>
using namespace std;

#define DELIMITER ','

int main(int argc, char* argv[]) {
  string resultFileName;
  bool isBench = false;

  if(argc == 3 && string(argv[1]) == "-b"){
    resultFileName = std::string(argv[2]);
    isBench = true;
}

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

  vector<tuple<unsigned int,double> > benchmarkTimes;

  for (size_t i = 0; i < instances.size(); i++) {
    clock_t start = clock();
    vector<vector<int > > weights = instances[i];
    tuple<int,int,vector<int> > res = Solver(weights);
    vector<int > path = get<2>(res);
    clock_t end = clock();
    double benchTime = (((double)(end - start)) / CLOCKS_PER_SEC);// * 1000; //dejo todo en milisegundos, para que no salte notación cientifica
    benchmarkTimes.push_back(make_tuple(instances[i].size() - 1, benchTime));

    cout << get<0>(res) << " " << get<1>(res) << " ";

    for (size_t i = 0; i < path.size(); i++) {
      cout << path[i];
      if (i == path.size()-1) cout << endl;
      else cout << " ";
    }
  }

  if(isBench){
    std::ofstream result;
    result.open(resultFileName);
    result << "Trabajos" << DELIMITER << "Tiempo_s" << std::endl;

    for(size_t i = 0; i < benchmarkTimes.size(); i++){
      result << get<0>(benchmarkTimes[i]) << DELIMITER;
      result << get<1>(benchmarkTimes[i]) << std::endl;
    }

    result.close();
  }

  return 0;
}
