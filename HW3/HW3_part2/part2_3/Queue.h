#ifndef QUEUE_H
#define QUEUE_H

#include "List.h"

template<class T>
class Queue:public List<T> {
public:
    Queue():List<T>(){}
    ~Queue(){}
    void Pop();
    void Push(T);
    bool isEmpty();
private:
};

/*******************************/
template <class T>
void Queue<T>::Pop() {
    this->DeleteFront();
}


/**/
template <class T>
void Queue<T>::Push(T newData) {
    this->InsertBack(newData);
}



/**/
template <class T>
bool Queue<T>::isEmpty() {
    return this->first == 0;
}

#endif