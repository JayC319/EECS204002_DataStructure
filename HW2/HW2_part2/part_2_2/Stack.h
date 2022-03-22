#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;


template <class T>
void ChangeSize1D(T*&a, const int oldSize, const int newSize) {
    if(newSize < 0 ) throw "New length must be >= 0";

    T* temp = new T[newSize];
    int number = min(oldSize, newSize);

    for(int i = 0; i < number; i++) {
        temp[i] = a[i];
    }

    delete [] a;
    a = temp;
} 





template <class T>
class Stack
{
private:
    int top, capacity;
    T* stack;
public:
    Stack(int stackCapacity):capacity(stackCapacity) {
        if(capacity < 1) throw "Stack capacity must be > 0";
        stack = new T[capacity];
        top = -1;
    }

    ~Stack() { delete []stack;}

    bool IsEmpty() const;

    void Push(const T& item);
    
    void Pop();

    T& Top() const;
};

template <class T>
inline bool Stack<T>::IsEmpty() const {
    return (top == -1);
}


template <class T>
inline T& Stack<T>::Top() const {
    if(IsEmpty()) throw "Stack is empty";
    return stack[top];
}

template<class T>
void Stack<T>::Push(const T& x) {
    if(top == capacity - 1) {
        ChangeSize1D(stack, capacity, 2 * capacity);
        capacity *= 2;
    }
    stack[++top] = x;
}

template<class T>
void Stack<T>::Pop() {
    if(IsEmpty()) throw "Stack is empty, cannot delete";
    stack[top--]. ~T();
}



#endif