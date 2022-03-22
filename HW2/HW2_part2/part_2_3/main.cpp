#include <iostream>
#include "Bag.h"
#include "Stack.h"
#include "Queue.h"
#include "Deque.h"


int main() {
    Stack<int> s1(10);
    Stack<float> s2(5);
    Queue<int> q1(10);
    Queue<float> q2(4);
    Deque<int> dq1(1);

    for(int i = 0; i < 10; i++) {
        
        //dq1.Push(i+100);
        dq1.PushFromFront(i);
        // cout << "Front index: " << dq1.getFront() << " Rear Index: " << dq1.getRear() << endl;
        // cout << "Front Element: " << dq1.Front() << " Rear Element: " << dq1.Rear() << endl;
        dq1.Push(i+100);
    }

    
    dq1.ShowProperties();

    for(int i = 0; i < 10; i++) {
        dq1.PopFromBack();
        dq1.Pop();
    }
    dq1.ShowProperties();


    for(int j = 0; j < 6; j++) {
        dq1.PushFromFront(j+10);
    }
    
    dq1.ShowProperties();

     for(int j = 0; j < 2; j++) {
        
        dq1.PushFromFront(j+10);
        dq1.Push(j);
    }
    dq1.ShowProperties();
    cout << "end" << endl;
}