#include "Queue.h"
#include <iostream>
using namespace std;


/* self defined copy function*/
template<class T>
void copy(T* newArray, T* oldArray, int front, int size, int capacity) {
    for (int i = 1; i <= size ; i++)
        newArray[i] = oldArray[(front + i) % capacity];
}


/* IsEmpty() class method*/
/*******************************************************************
 * returns a boolean varivble checking whether the queue is empty  *
 * *****************************************************************/
template <class T>
bool Queue<T>::IsEmpty() const  {
    if ((size == 0) && (front == rear))
        return 1;
    else
        return 0;
}


/* Push() class method*/
/***************************************
 * pushes a new element into the queue *
 ***************************************/
template<class T>
void Queue<T>::Push(const T& x) {
    if ((rear + 1) % capacity == front) {
        T* newQu = new T[2 * capacity];
        copy(newQu, queue, front, size, capacity);
        front = 0;
        rear = capacity - 1;
        capacity *= 2;
        delete[] queue;
        queue = newQu;
    }
    rear = (rear + 1) % capacity;
    queue[rear] = x;
    size++;
}


/*Pop class method*/
/************
 * 
 * **********/
template <class T>
void Queue<T>::Pop() {
    if(IsEmpty())
        throw "[Warning]: Queue is empty. Cannot delete any element.";
    front = (front + 1) % capacity;
    queue[front].~T();
    size--;
}

/*Capacity class method*/
/************
 * 
 * **********/
template <class T>
int Queue<T>::Capacity() const {
    return capacity;
}

/*Size() class method*/
/************
 * 
 * **********/
template <class T>
int Queue<T>::Size() const {
    return ((rear + capacity - front) % capacity);
}

/*Front() class method*/
/************
 * 
 * **********/
template<class T>
inline T& Queue<T>::Front() const {
    if (IsEmpty())
        throw "[Warning]: Queue is empty. No front element.";
    return queue[(front + 1) % capacity];
}

/*Rear() class method*/
/************
 * 
 * **********/
template<class T>
inline T& Queue<T>::Rear() const {
    if (IsEmpty())
        throw "[Warning]: Queue is empty. No rear element.";
    return queue[rear];
}

/*ShowProperty() class method*/
/************
 * 
 * **********/
template<class T>
void Queue<T>::ShowProperty() {
    cout << "show property: " << endl;
    cout << "-----------------------------------"<< endl;
    Show();
    cout << "queue size: " << Size() << endl;
    cout << "queue capacity: " << Capacity() << endl;
    if(size) {
        cout << "front element: " << Front() << endl;
        cout << "rear element: " << Rear() << endl;
    }
    
    cout << "-----------------------------------"<< endl;
    cout << endl;
}

/*Show() class method*/
/************
 * 
 * **********/
template<class T>
void Queue<T>::Show() {
    cout << "queue: " << endl;
    if (!size) {
        cout << "empty queue" << endl;
        return;
    }
    for (int i = 1; i <= size; i++ )
        cout << "  " << queue[(front + i) % capacity];
    cout << endl;
}

/*Merge() class method*/
/************
 * 
 * **********/
template<class T>
void Queue<T>::Merge(Queue<T>& b) {
    T* newQu = new T[Capacity() + b.Capacity()];
    
    int a_stackTerms = Size();
    int a_iter = 1;
    int b_stackTerms = b.Size();
    int b_iter = 1;
    int i = 1;

    while(a_stackTerms > 0 && b_stackTerms > 0) {
        newQu[i++] = queue[(front + a_iter) % Capacity()];
        a_stackTerms --;
        a_iter++;
        newQu[i++] = b.queue[(b.front + b_iter) % b.Capacity()];
        b_stackTerms --;
        b_iter++;
    }


    while (a_stackTerms > 0) {
        newQu[i++] = queue[(front + a_iter) % Capacity()];
        a_stackTerms--;
        a_iter++;
    }
    while (b_stackTerms > 0) {
        newQu[i++] = b.queue[(b.front + b_iter) % b.Capacity()];
        b_stackTerms--;
        b_iter++;
    }
    
    // set parameter
    front = 0;
    rear = i - 1;
    size = i - 1;
    capacity = capacity + b.Capacity();
    delete[] queue;
    queue = newQu;
    b.front = 0;
    b.rear = 0;
    b.size = 0;
    delete[] b.queue;
    b.queue = new T[b.Capacity()];
}




template class Queue<int>;
template class Queue<float>;
template class Queue<char>;
template class Queue<double>;

