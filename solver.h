#ifndef SOLVER_H

#include <vector>
#include <utility>
#include <set>
using namespace std;

void makePath(vector<int > pred, unsigned int node , vector<int >& sol);
void getPath(vector<int > pred, unsigned int node , vector<int >& sol);
vector<int> getPathComplement(const vector<int >& path);
tuple<int,int,vector<int> > Solver(vector<vector<int > > weights);

#define SOLVER_H
#endif
