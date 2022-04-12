#include "Chain.h"
#include <iostream>

using namespace std;


int main() {
    Chain <int> C1;

    cout << "\n*****testbench start*****" << endl;

    cout << "\n[test for InsertFront]:" << endl;
    for(int i = 0; i < 10; i++)
        C1.InsertFront(i);
    C1.display();

    cout << "\n[test for InsertBack]:" << endl;
    for(int i = 90; i < 105; i++)
        C1.InsertBack(i); 
    C1.display();

    cout << "\n[test for DeleteBack]:" << endl;
    for(int i = 0; i < 5; i++)
        C1.deleteBack(); 
    C1.display();

    cout << "\n[test for Front and Back]:" << endl;
    cout << "Front of C1 is: " << C1.Front() 
    << endl << "Back of C1 is: " << C1.Back() << endl;
    
    cout << "\n[test for Get()]:" << endl;
    cout << "5th element of the chain is: " << C1.Get(5) << endl;
    cout << "7th element of the chain is: " << C1.Get(7) << endl;
    cout << "7th element of the chain is: " << C1.Get(13) << endl;

    cout << "\n[test for Delete()]:" << endl;
    cout << "delete the 5th of the chain" << endl;
    C1.Delete(5);
    C1.display();

    cout << "\n[test for Insert()]:" << endl;
    cout << "Insert 55 as 5th element" << endl;
    int k = 55;
    C1.Insert(5, k);
    C1.display();

    cout << "\n[test for Size() to count the element number]:" << endl;
    cout << "Size of the chain is: " << C1.Size() << endl;

    cout << "\n[test for ReplaceNode() to change the data field of given node]:" << endl;
    cout << "replace the 7th node's data to 777" << endl;
    int j = 777;
    C1.ReplaceNode(7, j);
    C1.display();

    cout << "\n[test for insertion before kth node]:" << endl;
    cout << "Insert 666 before the 7th node" << endl;
    int p = 666;
    C1.insertBeforeK(7, p);
    C1.display();

    cout << "\n[test for delete all the odd Node]:" << endl;
    C1.deleteAllOddNode();
    C1.display();

    cout << "\n[test for divideMid()]:" << endl;
    Chain<int> sublist;
    C1.divideMid(&sublist);
    cout << "C1: ";
    C1.display();
    cout << "sublist: ";
    sublist.display();


    cout << "\n[test for deconcatenate]:" << endl;
 
    Chain<int>* C2;
    C2 = C1.deconcatenate(1);
    cout << "C1: ";
    C1.display();
    cout << "C2: ";
    C2->display();

    cout << "\n[test for merge]:" << endl;
    Chain<int>* mergelist;
    cout << "C2: ";
    C2->display();
    cout << "sublist: ";
    sublist.display();
    mergelist = C2->merge(&sublist);
    cout << "mergelist: ";
    mergelist->display();

    

    cout << "\n\n*****end*****" << endl;
}