#include "graph.h"
#include "edge.h"

#include <iostream>
#include <string>
#include <vector>


/***********************************************************************/

//Solo para arboles :'c
void incidenceFromParents(vector<int>& parents , vector<vector<int> >& adjList){

  for(size_t i = 1; i < parents.size(); i++){
    adjList[i].push_back(parents[i]);
    adjList[parents[i]].push_back(i);
  }
  return;
}

/***********************************************************************/

pair<int,int> DFS(vector<vector<int> >& T, vector<int>& visited, int depth, int actual){

  //Aumento la profundidad y marco el nodo como visitado
  visited[actual] = 1 ;
  pair<int,int> max = make_pair(actual,depth);

  for(auto it = begin(T[actual]); it != end(T[actual]) ; ++it){
    if(visited[*it] == 0 ){
      pair<int,int> res = DFS(T,visited,depth+1,*it);
      if(max.second < res.second) max = res;
    }
  }
  return  max;
}

/***********************************************************************/

//Devuelve el nodo a mayor distancia de n_0, SOLO PARA ARBOLES
int farthestNode(vector<vector<int> >& T, int n_0){

  int depth = 0;
  vector<int> visited(T.size(),0);
  visited[n_0] = 1;
  pair<int,int> max = DFS(T,visited,depth++, n_0);
  // devolvemos el nodo mas lejano
  return max.first;
}

/***********************************************************************/

int networkCost(Graph& network,vector<int>& parents){
  int cost = 0;
  for (size_t i = 1; i < parents.size(); i++) {
    // NOTE: El nodo 0 no tiene padre
    cost += network.weight(parents[i],i);
  }
  return cost;
}

/***********************************************************************/

vector<Edge> getLinks(Graph& network,vector<int>& parents){
  // Como es un arbol sabemos que m = n - 1
  vector<Edge> links(parents.size() - 1);
  for (size_t i = 1; i < parents.size(); i++) {
    // NOTE: El nodo 0 no tiene padre
    links[i-1].vertexA = i;
    links[i-1].vertexB = parents[i];
    links[i-1].weight = network.weight(parents[i],i);
  }
  return links;
}

/***********************************************************************/


bool search(vector<vector<int > >& T, vector<int>& visited, vector<int>& path,unsigned int current, unsigned int target){

  if (current == target) return true;
  visited[current] = 1;
  for (auto it = begin(T[current]); it != end(T[current]); ++it) {
    if(visited[*it] == 0){
      path.push_back(*it);
      if (search(T,visited,path,*it,target)) return true;
      path.pop_back();
    }
  }
  return false;

}

vector<int> makePath(vector<vector<int > >&  T, unsigned int root,unsigned int target){
  vector<int> visited(T.size(),0);
  vector<int> S;
  S.push_back(root);
  bool ok = search(T,visited,S,root,target);
  return S;
}

/***********************************************************************/

int getMaster(vector<int>& parents){

  vector<vector<int> > T(parents.size());
  incidenceFromParents(parents,T);
  int v1,v2;
  v1 = farthestNode(T,0);
  v2 = farthestNode(T,v1);

  cout << "Nodes: " << v1 << " " << v2 << endl;

  vector<int> path =  makePath(T,v1,v2);
  cout << "< ";
  for (size_t i = 0; i < path.size(); i++) {
    cout << path[i] << " " ;
  }
  cout << ">" << endl;

  return path[path.size()/2];
}


int main(){
    std::vector<Graph> networks;

    unsigned int serverCount;
    unsigned int links;

    // La entrada concluye con una lı́nea comenzada por 0, la cual no debe procesarse.
    std::cin >> serverCount;
    while(serverCount != 0){
        std::cin >> links;
        vector<Edge> linksList;

        for(unsigned int i = 0; i < links; i++){
            Edge e;
            std::cin >> e.vertexA;
            std::cin >> e.vertexB;
            std::cin >> e.weight;
            e.vertexA--; // Los servidores se ingredan numerados del 1 a serverCount
            e.vertexB--;
            linksList.push_back(e);
        }

        networks.push_back(Graph(serverCount, linksList));

        // Siguiente instancia...
        std::cin >> serverCount;
    }
    for(unsigned int i = 0; i < networks.size(); i++){
        vector<int> parents = networks[i].prim();
        vector<Edge> linksList = getLinks(networks[i],parents);

        int solutionCost = networkCost(networks[i],parents);
        int masterServer = getMaster(parents);
        int linksCount = linksList.size();

        std::cout << solutionCost << " " << masterServer << " " << linksCount << " ";
        // Luego de calcular el arbol generador minimo, cada nodo tiene un solo padre
        for(unsigned int i = 0; i < linksList.size(); i++){
            std::cout << linksList[i].vertexA << " " << linksList[i].vertexB << " ";
        }


        // RECETA PARA EL CAMINO MAXIMO (no pregunten):
        // 1: dfs de un nodo random (funcion farthestNode (esta implementada))
        // 2: tiras dfs del nodo que devuelve dfs
        // 3: ???
        // 4: Profit
        // 5: tu camino maximo es el camino entre el nodo que devolvio el primer dfs y el segundo

        // Tomar el elemnto en la posicion tam(camino)/2 parte entera inferior o algo asi

        std::cout << std::endl;
    }

    return 0;
}
