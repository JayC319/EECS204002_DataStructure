#include <iostream>
#include "Graph.h"
using namespace std;

int main() {
    Graph g1(8), g2(8), g3(10);

    /*setup for graph1*/
    g1.InsertEdge(0, 1);
    g1.InsertEdge(0, 2);
    g1.InsertEdge(1, 3);
    g1.InsertEdge(2, 3);
    g1.InsertEdge(4, 5);
    g1.InsertEdge(5, 6);
    g1.InsertEdge(6, 7);
   


    // /*set up for graph2*/
    g2.InsertEdge(0, 1);
    g2.InsertEdge(0, 2);
    g2.InsertEdge(1, 3);
    g2.InsertEdge(1, 4);
    g2.InsertEdge(2, 5);
    g2.InsertEdge(2, 6);
    g2.InsertEdge(3, 7);
    g2.InsertEdge(4, 7);
    g2.InsertEdge(5, 7);
    g2.InsertEdge(6, 7);


    // /*set up for graph3*/
    g3.InsertEdge(0, 1);
    g3.InsertEdge(1, 2);
    g3.InsertEdge(1, 3);
    g3.InsertEdge(2, 4);
    g3.InsertEdge(3, 4);
    g3.InsertEdge(3, 5);
    g3.InsertEdge(5, 6);
    g3.InsertEdge(5, 7);
    g3.InsertEdge(6, 7);
    g3.InsertEdge(7, 8);
    g3.InsertEdge(7, 9);

    cout << "-----graph 1-----" << endl;
    cout << "\n[Breadth First Search]" << endl;
    cout << "BFS(0): ";
    g1.BFS(0);
    cout << "BFS(3): ";
    g1.BFS(3);
    cout << "BFS(7): ";
    g1.BFS(7);

    cout << "\n[Depth First Search]" << endl;
    cout << "DFS(0): ";
    g1.DFS(0);
    cout << "DFS(3): ";
    g1.DFS(3);
    cout << "DFS(7): ";
    g1.DFS(7);

    cout << "Components and DfnLow" << endl;
    cout << "g1.Componenets: "; 
    g1.Components();
    cout << "g1.DfnLow(3): ";
    g1.DfnLow(3);


    cout << "\n\n-----graph 2-----" << endl;
    cout << "\n[Breadth First Search]" << endl;
    cout << "BFS(0): ";
    g2.BFS(0);
    cout << "BFS(3): ";
    g2.BFS(3);
    cout << "BFS(7): ";
    g2.BFS(7);

    cout << "\n[Depth First Search]" << endl;
    cout << "DFS(0): ";
    g2.DFS(0);
    cout << "DFS(3): ";
    g2.DFS(3);
    cout << "DFS(7): ";
    g2.DFS(7);

    cout << "Components and DfnLow" << endl;
    cout << "g2.Componenets: "; 
    g2.Components();
    cout << "g2.DfnLow(3): ";
    g2.DfnLow(3);
    

    cout << "\n\n-----graph 3-----" << endl;
    cout << "\n[Breadth First Search]" << endl;
    cout << "BFS(0): ";
    g3.BFS(0);
    cout << "BFS(3): ";
    g3.BFS(3);
    cout << "BFS(7): ";
    g3.BFS(7);

    cout << "\n[Depth First Search]" << endl;
    cout << "DFS(0): ";
    g3.DFS(0);
    cout << "DFS(3): ";
    g3.DFS(3);
    cout << "DFS(7): ";
    g3.DFS(7);

    cout << "Components and DfnLow" << endl;
    cout << "g3.Componenets: "; 
    g3.Components();
    cout << "g3.DfnLow(3): ";
    g3.DfnLow(3);

}