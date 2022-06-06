#include <iostream>
#include "MatrixWDigraph.h"
using namespace std;

int main() {
    cout << "-----graph1-----" << endl;
    MatrixWDigraph g1(8), g1_(6), g1__(6);
    g1.insertEdge(1, 0, 300);
    g1.insertEdge(2, 0, 1000);
    g1.insertEdge(2, 1, 800);
    g1.insertEdge(3, 2, 1200);
    g1.insertEdge(4, 3, 1500);
    g1.insertEdge(4, 5, 250);
    g1.insertEdge(5, 3, 1000);
    g1.insertEdge(5, 6, 900);
    g1.insertEdge(5, 7, 1400);
    g1.insertEdge(6, 7, 1000);
    g1.insertEdge(7, 0, 1700);

    g1_.insertEdge(0, 1, 50);
    g1_.insertEdge(0, 2, 45);
    g1_.insertEdge(0, 3, 10);
    g1_.insertEdge(1, 2, 10);
    g1_.insertEdge(1, 3, 15);
    g1_.insertEdge(2, 4, 30);
    g1_.insertEdge(3, 0, 20);
    g1_.insertEdge(3, 4, 15);
    g1_.insertEdge(4, 1, 20);
    g1_.insertEdge(4, 2, 35);
    g1_.insertEdge(5, 4, 3);

    g1__.insertEdge(0, 1, 20);
    g1__.insertEdge(0, 2, 15);
    g1__.insertEdge(1, 0, 2);
    g1__.insertEdge(1, 4, 10);
    g1__.insertEdge(1, 5, 30);
    g1__.insertEdge(2, 3, 4);
    g1__.insertEdge(2, 5, 10);
    g1__.insertEdge(4, 3, 15);
    g1__.insertEdge(5, 3, 4);
    g1__.insertEdge(5, 4, 10);

    cout << "Graph 1:" << endl;
    g1.Dijkstra(4);
    cout << "Graph 1' :" << endl;
    g1_.Dijkstra(0);
    cout << "Graph 1'' : " << endl;
    g1__.Dijkstra(0);


    cout << "-----graph2-----" << endl;
    MatrixWDigraph g2(7), g2_(3);
    g2.insertEdge(0, 1, 6);
    g2.insertEdge(0, 2, 5);
    g2.insertEdge(0, 3, 5);
    g2.insertEdge(1, 4, -1);
    g2.insertEdge(2, 1, -2);
    g2.insertEdge(2, 4, 1);
    g2.insertEdge(3, 2, -2);
    g2.insertEdge(3, 5, -1);
    g2.insertEdge(4, 6, 3);
    g2.insertEdge(5, 6, 3);

    g2_.insertEdge(0, 1, 7);
    g2_.insertEdge(0, 2, 5);
    g2_.insertEdge(1, 2, -5);

    cout << "Graph 2:" << endl;
    g2.Bellman_Ford(0);

    cout << "Graph 2':" << endl;
    g2_.Bellman_Ford(0);


    cout << "-----graph3-----" << endl;
    MatrixWDigraph g3(3);

    g3.insertEdge(0, 1, 4);
    g3.insertEdge(0, 2, 11);
    g3.insertEdge(1, 0, 6);
    g3.insertEdge(1, 2, 2);
    g3.insertEdge(2, 0, 3);
    
    cout << "Graph 3: " << endl;
    g3.Floyd();

    cout << "Graph 2: " << endl;
    g2.Floyd();

}