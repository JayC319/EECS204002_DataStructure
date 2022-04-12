#ifndef QUEUE_H
#define QUEUE_H
#include "Bag.h"


/* self defined copy function*/
template<class T>
void copy(T* newArray, T* oldArray, int front, int size, int capacity) {
    for (int i = 1; i <= size ; i++)
        newArray[i] = oldArray[(front + i) % capacity];
}



/*queue class derived from bag*/
/*this uses a circular queue approach*/
template<class T>
class Queue:public Bag<T> {
public:
    Queue(int);
    ~Queue();
    void Pop();
    void Push(const T&);
    void Print() const;
    void ShowProperties();
    T& Front() const {return this->array[(front+1)%this->capacity];}
    T& Rear()  const {return this->array[rear];}
protected:
    int front, rear;
};

template <class T>
Queue<T>::Queue(int stackCapacity):Bag<T>(stackCapacity) {
    front = 0;
    rear = 0;
}

template<class T>
Queue<T>::~Queue() {}

/*Pop*/
/*********************************************************
 * @brief                                                *
 * This pops the front element of the queue if not empty *
 *                                                       *
 * @tparam T                                             *
 *********************************************************/
template<class T>
void Queue<T>::Pop() {
    if (this->IsEmpty())
        throw "[Error]: Queue is empty. Cannot delete.";
    
    front = (front + 1) % this->capacity;
    this->array[front].~T();
    this->size--;
}

/*Push*/
/*******************************************************
 * @brief                                              *
 * This pushes element into the queue                  *
 * Is the queue is becoming full resizes the queue     *
 *                                                     *
 * @tparam T                                           *
 * @param x  takes the element                                          *
 *******************************************************/
template<class T>
void Queue<T>::Push(const T& x) {
    if ((rear + 1) % this->capacity == front) {
        T* newQu = new T[2 * this->capacity];
        copy(newQu, this->array, front, this->size, this->capacity);
        front = 0;
        rear = this->capacity - 1;
        this->capacity *= 2;
        delete[] this->array;
        this->array = newQu;
    }
    rear = (rear + 1) % this->capacity;
    this->array[rear] = x;
    this->size++;
}

/*Print*/
/****************************************************
 * @brief                                           *
 *  This prints out the bag element sequentially    *
 *                                                  *
 * @tparam T                                        *
 ****************************************************/
template<class T>
void Queue<T>::Print() const {
    cout << "queue: " << endl;
    if (!this->Size()) {
        cout << "empty queue" << endl;
        return;
    }
    for (int i = 1; i <= this->Size(); i++ )
        cout << "  " << this->array[(front + i) % this->capacity];
    cout << endl;
}


/*ShowProperties*/
/*********************************************
 * @brief This shows property of the bag     *
 * By using Size() to show size              *
 * Capacity() to show capacity               *
 * Print() to show all elements sequentially *
 * Front() to show the front element         *
 * Rear() to show the rear element           *                                          *
 * @tparam T                                 *
 *********************************************/
template<class T>
void Queue<T>::ShowProperties() {
    cout << "show property: " << endl;
    cout << "-----------------------------------"<< endl;
    Print();
    cout << "queue size: " << this->Size() << endl;
    cout << "queue capacity: " << this->Capacity() << endl;
    if(this->size) {
        cout << "Front element: " << this->Front() << endl;
        cout << "Rear element: " << this->Rear() << endl;
    }
        
    cout << "-----------------------------------"<< endl;
    cout << endl;
}
















#endif