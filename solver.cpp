#include <vector>
#include <set>
#include "solver.h"
#include <iostream>
#include <limits>
#include <tuple>
#include "graph.h"


using namespace std;
#define INFINITY numeric_limits<int>::max();

/* NOTE: las funciones makePath y getPath hacen casi lo mismo pero makePath es
mas conveniente a la hora de calcular el complemento de un camino */


void makePath(vector<int > pred, unsigned int node , vector<int >& sol){
 if(node == 0) sol.push_back(0);
 else{
   makePath(pred,pred[node],sol);
   sol.push_back(node);
 }
}


void getPath(vector<int > pred, unsigned int node , vector<int >& sol){
  /* Devuelve un array donde la posicion i-esima indica si el nodo esta en el camino */
 if(node == 0) return;
 else{
   sol[node] = 1;
   getPath(pred,pred[node],sol);
 }
}

vector<int> getPathComplement(const vector<int >& path){

  vector<int > sol(path.size(),0);
  for (size_t i = 0; i < path.size(); i++) {
    sol[i] = path[i] == 1? 0 : 1;
  }
  return sol;
}




tuple<int,int,vector<int> > Solver(vector<vector<int > > weights){



  int num_v = weights.size();
  /* Inicializamos la matriz de adyacencia
   * con el orden topologico de los problemas */
  vector<vector<bool > > M(num_v, vector<bool >(num_v,0)) ;

  for (size_t i = 0; i < num_v; i++) {
    for (size_t j = i; j < num_v ; j++) {
      M[i][j] = true;
    }
  }

  Graph g = Graph(M,weights);


  /* Buscamos caminos minimos */
  pair< vector<int >, vector<int> > res = g.Dijkstra(0);

  vector<int > pi = res.first;
  vector<int > pred = res.second;
  vector<int > pi_comp(pi.size(),0);


  for (size_t i = 1; i < pi.size(); i++) {
    vector<int > path(pi.size(),0);
    vector<int > pathComp(pi.size(),0);
    getPath(pred,i,path);
    pathComp = getPathComplement(path);
    pi_comp[i] = g.pathSum(pathComp);
  }


  int min = INFINITY;
  int sol;

  /* buscamos a partir del 1 */
  for (size_t i = 1; i < pi.size(); i++) {
    if (pi[i]+pi_comp[i] < min ) {
      min = pi[i] + pi_comp[i];
      sol = i;
    }
  }

  vector<int> bestPath = {};
  makePath(pred,sol,bestPath);
  tuple<int,int,vector<int>  > solucion(min,bestPath.size(),bestPath);

  return solucion;

}
