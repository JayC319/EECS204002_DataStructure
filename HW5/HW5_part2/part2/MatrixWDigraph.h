#ifndef MATRIXWDIGRAPH_H
#define MATRIXWDIGRAPH_H
#include <iostream>
#include <limits.h>
#include <stack>
#include <iomanip>
using namespace std;
class MatrixWDigraph {
public:
    MatrixWDigraph();
    MatrixWDigraph(const int vertexNum);
    ~MatrixWDigraph();
    bool isEmpty() const {return n == 0;}
    int numberOfVertices() const {return n;}
    int numberOfEdges() const {return e;}
    void insertEdge(const int u, const int v, const int length);
    void showAdjMatrix() const;
    void showDict(const int s, const int x) const;
    
    void Dijkstra(const int v);
    void Bellman_Ford(const int v);
    void Floyd();
private:
    int n;
    int e; 
    int **adjacency_matrix;
    int *distance;
    int *predecessor;
    int **asp_matrix;
};




#endif