#ifndef DEQUE_H
#define DEQUQ_H
#include "Queue.h"

template<class T>
void midcopy(T* newArray, T* oldArray, int front, int size, int capacity) {
    for (int i = 1; i <= size ; i++)
        newArray[capacity + i] = oldArray[(front + i) % capacity];
}


template<class T>
class Deque:public Queue<T> {
private:

public:
    Deque(int);
    ~Deque();
    void PushFromFront(const T& x);
    void PopFromBack();
    int getFront(){return this->front;}
    int getRear(){return this->rear;}
};


template <class T>
Deque<T>::Deque(int stackCapacity):Queue<T>(stackCapacity) {
    this->front = stackCapacity / 2;
    this->rear = stackCapacity / 2;
}

template<class T>
Deque<T>::~Deque() {}

template<class T>
void Deque<T>::PopFromBack() {
    if(this->IsEmpty())
        throw "[Warning]: Queue is empty. Cannot delete any element.";
    
    this->array[this->rear].~T();
    this->size--;
    if(!this->rear)
        this->rear = this->capacity-1;
    else
        this->rear--;
}

template<class T>
void Deque<T>::PushFromFront(const T& x) {
    if((this->Size()+1) == this->Capacity()) {
        T* newQu = new T[2 * this->capacity];
        midcopy(newQu, this->array, this->front, this->size, this->capacity);
        this->front = this->capacity;
        this->rear = (this->capacity + this->size) ;
        this->capacity *= 2;
        delete[] this->array;
        this->array = newQu;
    }

    this->array[this->front] = x;
    if(!this->front)
        this->front = (this->capacity-1);
    else 
        this->front -= 1;
        
    this->size++;

}



#endif