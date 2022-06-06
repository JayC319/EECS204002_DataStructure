#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
using namespace std;

typedef struct EDGE {
    int terminal_vertex;
    struct EDGE *next_edge;
} Edge;


class Graph {
public:
    Graph(const int vertex_num);
    ~Graph();
    bool isEmpty();
    int NumberOfVertex() const {return n;}
    int NumberOfEdge() const {return e;}
    void InsertEdge(const int u, const int v);
    void ShowGraph() const;
    void BFS(const int root) const;
    void DFS(const int root) const;
    void DFS(const int v, bool visited[]) const;
    void Components() const;
    void DfnLow(const int root);
    void DfnLow(const int u, const int v);

private:
    int n;
    int e;
    vector<Edge*> adjacent_list;
    int *dfn;
    int *low;
    int num;
};


#endif // GRAPH_H



