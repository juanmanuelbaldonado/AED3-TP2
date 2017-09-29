#ifndef SOLVER_H

#include <vector>
#include <utility>
#include <set>
using namespace std;

struct Path{
  unsigned int cost;
  int predecesor;
  unsigned int first_comp;
  unsigned int last_comp;
};


unsigned int getCost(const vector<vector<int > >& weights, vector<vector<int > >& costMatrix, unsigned int i, unsigned int j);
tuple<int,int,vector<int> > Solver(vector<vector<int > >& weights);
vector<int> recoverSolution(const vector<Path>& T, unsigned int N);
#define SOLVER_H
#endif
