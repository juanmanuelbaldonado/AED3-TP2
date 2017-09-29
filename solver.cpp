#include <vector>
#include <set>
#include <iostream>
#include <limits>
#include <tuple>
#include <iterator>
#include <algorithm>
#include "solver.h"

using namespace std;
#define INFINITY numeric_limits<int>::max();

unsigned int getCost(const vector<vector<int > >& weights, vector<vector<int > >& costMatrix, unsigned int i, unsigned int j){

  if (costMatrix[i][j] != -1) return costMatrix[i][j];
  if (i == j) return 0;
  if (i == j-1) return weights[i][j];

  int diff = i+2 == j ? -weights[i][j-1] : weights[j-2][j-1] - weights[i][j-1];
  costMatrix[i][j] = getCost(weights,costMatrix,i,j-1) + diff + weights[i][j];
  return costMatrix[i][j];
}

vector<int> recoverSolution(const vector<Path>& T, unsigned int N){

  int next = N - 1;
  vector<int > solution;
  while (T[next].predecesor != -1) {
    solution.push_back(next);
    next = T[next].predecesor;
  }
  std::reverse(std::begin(solution), std::end(solution));
  return solution;
}


tuple<int,int,vector<int> > Solver(vector<vector<int > >& weights){

  unsigned int N = weights.size();
  vector<vector<int > > costMatrix(N, vector<int >(N,-1));

  vector<Path > T(N);
  T[0].cost = 0;
  T[0].predecesor = -1;
  T[0].first_comp = 0;
  T[0].last_comp = 0;

  unsigned int cost,min_cost;

  for (size_t i = 1; i < N; i++) {
    min_cost = INFINITY;
    for (size_t j = 0; j < i; j++) {
      cost = T[j].cost + getCost(weights,costMatrix,j,i);
      cost += (j + 1 < i) ? weights[T[j].last_comp][j+1] : 0;

      if (cost < min_cost){
        T[i].cost = cost;
        T[i].predecesor = j;
        T[i].first_comp = (j + 1 < i) ? j + 1 : T[j].last_comp;
        T[i].last_comp = (j + 1 < i) ? i - 1 : T[j].last_comp;
        min_cost = cost;
      }
    }
  }
  vector<int > solution = recoverSolution(T,N);
  return make_tuple(T[N-1].cost,solution.size(),solution);
}
