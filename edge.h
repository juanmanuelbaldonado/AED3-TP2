#ifndef EDGE_H
#define EDGE_H

class Edge{
public:
    unsigned int vertexA;
    unsigned int vertexB;
    unsigned int weight;

    Edge(){
    	vertexA = 0;
    	vertexB = 0;
    	weight = 0;
    }

    Edge(unsigned int A,unsigned int B,unsigned int w){
    	vertexA = A;
    	vertexB = B;
    	weight = w;
    }

    bool operator<(const Edge& e2) const{
    	return weight < e2.weight;
    }
    bool operator==(const Edge& e2) const{
    	return weight == e2.weight && vertexA == e2.vertexA && vertexB == e2.vertexB;
    } 



};

#endif