#include <iostream>
#include "Graph.h"

using namespace std;


/* constructor */
Graph::Graph(const int vertex_num) {
    n = vertex_num;
    e = 0;
    num = 0;
    for(int i = 0; i < n; i++)
        adjacent_list.push_back(0);
}


/* destructor*/
Graph::~Graph() {}


/* InsertEdge */
void Graph::InsertEdge(const int u, const int v) {
    e++;
    Edge *u_to_v = new Edge;
    Edge *v_to_u = new Edge;
    u_to_v->terminal_vertex = v;
    u_to_v->next_edge = 0;
    v_to_u->terminal_vertex = u;
    v_to_u->next_edge = 0;

    if (adjacent_list[u] == 0) 
        adjacent_list[u] = u_to_v;
    
    else {
        Edge* iter = adjacent_list[u];
        while(iter->next_edge)
            iter = iter->next_edge;
        iter->next_edge = u_to_v;
    }

    if (adjacent_list[v] == 0)
        adjacent_list[v] = v_to_u;
    
    else {
        Edge* iter = adjacent_list[v];
        while(iter->next_edge)
            iter = iter->next_edge;
        iter->next_edge = v_to_u;
    }
}


/*ShowGraph*/
void Graph::ShowGraph() const {
    for(int i = 0; i < n; i++) {
        cout << i << " : ";
        Edge* iter = adjacent_list[i];
        while(!iter) {
            cout << iter->terminal_vertex << " ";
            iter = iter->next_edge;
        }
        cout << endl;
    }
}


/* Breadth First Search*/
void Graph::BFS(const int root) const {
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;
    
    visited[root] = true;

    queue<int> q;
    q.push(root);

    while(!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";

        for(Edge* iter = adjacent_list[v]; iter != NULL; iter = iter->next_edge) {
            int w = iter->terminal_vertex;
            if(!visited[w]) {
                q.push(w);
                visited[w] = true;
            }
        }
    }   
    cout << endl;
    delete[] visited;
}


/*Depth First Search Driver*/
void Graph::DFS(const int root) const {
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++) 
        visited[i] = false;
    
    DFS(root, visited);
    cout << endl;
    delete[] visited;
} 


/*Depth First Search Workhorse*/
void Graph::DFS(const int v, bool visited[]) const{
    visited[v] = true;
    cout << v << " ";
    for(Edge* iter = adjacent_list[v]; iter != NULL; iter = iter->next_edge) {
        int w = iter->terminal_vertex;
        if(!visited[w])
            DFS(w, visited);
    }
}


void Graph::Components() const {
    int count = 0;
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;

    for(int i = 0 ; i < n; i++) {
        if(!visited[i]) {
            count++;
            cout << "[ ";
            DFS(i, visited);
            cout << "} ";
        }
    }
    cout << "total component number: " << count << endl;
    delete[] visited;
}


/* DfnLow driver*/
void Graph::DfnLow(const int root) {
    num = 1;
    dfn = new int[n];
    low = new int[n];

    for(int i = 0; i < n; i++)
        dfn[i] = low[i] = 0;
    
    DfnLow(root, -1);

    cout << " ";
        cout << "\ndfn[]: ";
        for(int i = 0; i < n; i++)
            cout << dfn[i] << " ";
        cout << "\nlow[]: ";
        for(int i = 0; i < n; i++)
            cout << low[i] << " ";
        cout << endl;

        delete[] dfn;
        delete[] low;
}


/*DfnLow Workhorse*/
void Graph::DfnLow(const int u, const int v) {
    dfn[u] = low[u] = num++;
    for(Edge *iter = adjacent_list[u]; iter != 0; iter = iter->next_edge) {
        int w = iter->terminal_vertex;
        if(dfn[w] == 0) {
            DfnLow(w, u);
            low[u] = min(low[u], low[w]);
        }
        else if (w != v)
            low[u] = min(low[u], dfn[w]);
    }
}
