#include <iostream>
#include "Bag.h"
#include "Stack.h"
#include "Queue.h"
#include "Deque.h"


int main() {
    Stack<int> s1(10);
    Stack<float> s2(5);
    Queue<int> q1(10);
    Queue<float> q2(5);
    Deque<int> dq1(10);
    Deque<float> dq2(5);


    /* tesbench for stack */
    cout << "[This is test bench for Stack]" << endl;
    cout << "--test pushing--" << endl;
    for(int i = 0; i < 11; i++) {
        s1.Push(i);
        s2.Push((float)i/101);
    }
    cout << "\n[stack1]:" << endl;
    s1.ShowProperties();
    cout << "\n[stack2]:" << endl;
    s2.ShowProperties();

    cout << "--test popping--" << endl;
    for(int i = 0; i < 7; i++) {
        s1.Pop();
        s2.Pop();
    }

    cout << "\n[stack1]:" << endl;
    s1.ShowProperties();
    cout << "\n[stack2]:" << endl;
    s2.ShowProperties();

    cout << "--test pushing--" << endl;

    for(int i = 0; i < 10; i++) {
        s1.Push(i+100);
        s2.Push((float)i/10.1);
    }   

    cout << "\n[stack1]:" << endl;
    s1.ShowProperties();
    cout << "\n[stack2]:" << endl;
    s2.ShowProperties();

    cout << "\n\n*******************************\n[This is testbench for queue]\n*******************************" << endl;
    cout << "--test pushing--" << endl;
    for(int i = 0; i < 11; i++) {
        q1.Push(i);
        q2.Push((float)i/101);
    }
    cout << "\n[queue1]:" << endl;
    q1.ShowProperties();
    cout << "\n[queue2]:" << endl;
    q2.ShowProperties();

    cout << "--test popping--" << endl;
    for(int i = 0; i < 7; i++) {
        q1.Pop();
        q2.Pop();
    }

    cout << "\n[queue1]:" << endl;
    q1.ShowProperties();
    cout << "\n[queue2]:" << endl;
    q2.ShowProperties();

    cout << "--test pushing--" << endl;

    for(int i = 0; i < 10; i++) {
        q1.Push(i+100);
        q2.Push((float)i/10.1);
    }   

    cout << "\n[queue1]:" << endl;
    q1.ShowProperties();
    cout << "\n[queue2]:" << endl;
    q2.ShowProperties();


    /* testbench for deque */
    cout << "\n\n*******************************\n[This is testbench for deque]\n*******************************" << endl;

    for(int i = 0; i < 10; i++) {
         dq1.PushFromFront(i);
         dq2.PushFromFront((float)i/10);
         dq1.Push(i+100);
         dq2.Push((float) i/5);
    }

    
    cout << "\n[deque1]:" << endl;
    dq1.ShowProperties();
    cout << "\n[deque2]:" << endl;
    dq2.ShowProperties();

    for(int i = 0; i < 10; i++) {
        dq1.PopFromBack();
        dq1.Pop();
        dq2.PopFromBack();
        dq2.Pop();
    }
    
    cout << "\n[deque1]:" << endl;
    dq1.ShowProperties();
    cout << "\n[deque2]:" << endl;
    dq2.ShowProperties();

    
    for(int i = 0; i < 10; i++) {
        dq1.PushFromFront(i+2);
        dq1.Push(i+50);
        dq2.PushFromFront((float)i/4);
        dq2.Push(i+0.02);
    }

    cout << "\n[deque1]:" << endl;
    dq1.ShowProperties();
    cout << "\n[deque2]:" << endl;
    dq2.ShowProperties();


    return 0;
}