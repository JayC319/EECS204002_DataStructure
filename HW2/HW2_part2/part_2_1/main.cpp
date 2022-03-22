#include <iostream>
#include "Queue.h"
//#include "Queue.cpp"

using namespace std;
int main() 
{
    
    Queue<int> q1(5);


    q1.Push(1);
    q1.Push(5);
    q1.Push(7);
    
    q1.ShowProperty();

    q1.Push(8);  
    q1.ShowProperty();

   
    q1.Push(9);
    q1.ShowProperty();

    q1.Pop();
    q1.ShowProperty();

    q1.Push(19);
    q1.Push(26);
    q1.ShowProperty();

    Queue<int> q2(5);
    for(int k = 0; k < 7; k++) {
        q2.Push(k);
    }

    q2.ShowProperty();

    q1.Merge(q2);
    q1.ShowProperty();
    q2.ShowProperty();
    q1.Push(19);
    q1.Push(19);
    q1.ShowProperty();    
}