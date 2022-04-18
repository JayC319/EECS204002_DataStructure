#ifndef STACK_H
#define STACK_H

#include "List.h"

template<class T>
class Stack:public List<T> {
public:
    Stack():List<T>(){}
    ~Stack(){}
    void Pop();
    void Push(T newdata);
    bool isEmpty();
    T Top();
private:
};


template <class T>
void Stack<T>::Pop() {
    this->DeleteFront();
}


/**/
template <class T>
void Stack<T>::Push(T newData) {
    this->InsertFront(newData);
}


/**/
template <class T>
bool Stack<T>::isEmpty() {
    return this->first == NULL;
}


template <class T>
T Stack<T>::Top() {
    return this->Front();
}

#endif