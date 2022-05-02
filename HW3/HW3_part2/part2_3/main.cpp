#include "List.h"
#include "Queue.h"
#include "Stack.h"
#include <iostream>
using namespace std;

int main() {
    
    List<int> L1;
    Queue<int> Q1; // derived from List
    Stack<int> S1; // derived from List

    cout << "\n*****testBench Start*****" << endl;
    cout << "[test for InsertFront for List and Push for Queue and Stack" << endl;

    for(int i = 0; i < 10; i++) {
        L1.InsertBack(i-10);
        L1.InsertFront(i+10);
        Q1.Push(i);
        S1.Push(i);
    }


    cout << "List: " << L1 << endl;
    cout << "Queue: " << Q1 << endl;
    cout << "Stack: " << S1 << endl;


    cout << "\n[test for DeleteFront and DeleteBack for list " 
     << "and Pop for Queue and Stack]" << endl;
    for(int i = 0; i < 5; i++) {
        L1.DeleteFront();
        L1.DeleteBack();
        Q1.Pop();
        S1.Pop();
    }

    cout << "List: " << L1 << endl;
    cout << "Queue: " << Q1 << endl;
    cout << "Stack: " << S1 << endl;

    cout << "\n[test for Front and Back for list "
         << "and Top for Stack and Front for Queue]" << endl;

    cout << "Front of List: " << L1.Front() << " Back of List: " << L1.Back() << endl;
    cout << "Top of stack: " << S1.Top() << endl;
    cout << "Front of Queue: " << Q1.Front() << endl; 

    cout << "\n[test for Get for list] " << endl;
    cout << "L1" << L1 << endl;
    cout << "The 5th element of the list is: " << L1.Get(5) << endl; 
    cout << "The 7th element of the list is: " << L1.Get(7) << endl; 

    cout << "\n[test for Delete for list] " << endl;
    cout << "L1 before delete the 5th element " << L1 << endl;
    L1.Delete(5);
    cout << "L1 after delete the 5th element " << L1 << endl;
    
    cout << "\n[test for Insert for list] "  << endl;
    cout << "L1 before Insert 666 as 8th element " << L1 << endl;
    L1.Insert(8, 666);
    cout << "L1 after Insert 666 as 8th element " << L1 << endl;
    
    cout << "\n[test of summation of speical mult]: " << endl;
    cout << "L1: " << L1 << endl;
    cout << L1.specialMult() << endl; 

    cout << "\n[test for Reverse() of the list class" << endl;
    cout << "L1 before reverse: " << L1 << endl;
    L1.Reverse();
    cout << "L1 after reverse: " << L1 << endl;
   
    cout << "\n*****end of testbench*****" << endl;
}


