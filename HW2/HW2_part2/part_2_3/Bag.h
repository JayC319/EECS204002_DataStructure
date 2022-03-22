#ifndef BAG_H
#define BAG_H
#include <iostream>

using namespace std;

template<class T>
class Bag {
protected:
    T *array;
    int top, capacity, size;
public:
    Bag(int);
    virtual ~Bag();
    virtual int Size() const;
    virtual int Capacity() const;
    virtual bool IsEmpty() const;
    virtual T& Element() const;
    virtual void Push(const T&);
    virtual void Pop();
    virtual void Print() const;
    virtual void ChangeSize1D();
    virtual void ShowProperties();
};

/* class Bag method */
/*----------------------------------------------*/



template<class T>
Bag<T>::Bag(int bagCapacity):capacity(bagCapacity) {
    if(bagCapacity < 1)
        throw "Capacity must be > 0";
    array = new T[capacity];
    top = -1;
    size = 0;
}

template<class T>
Bag<T>::~Bag() {
    delete[] array;
}


template<class T>
int Bag<T>::Size() const {
    return size;
}

template<class T>
int Bag<T>::Capacity() const {
    return capacity;
}


template<class T>
bool Bag<T>::IsEmpty() const {
    return (Size() == 0);
}

template<class T>
T& Bag<T>::Element() const {
    if(IsEmpty())
        throw "Bag is empty";
    return array[top];
}

template<class T>
void Bag<T>::Push(const T& x) {
    if(size == capacity) {
        ChangeSize1D();
        capacity *= 2;
    }
    array[++top] = x;
    size++;
}

template<class T>
void Bag<T>::Pop() {
    if (IsEmpty())
        throw "Bag is empty";
    array[top--].~T();
    size--;
}

template<class T>
void Bag<T>::Print() const{
    for(int i = 0; i < size; i++)
        cout << "[" << array[i] << "]";
    cout << endl;
}

template<class T>
void Bag<T>::ChangeSize1D() {
    int newSize = 2* Capacity();
    T* newArr = new T[newSize];
    for(int i = 0; i < size; i++)
        newArr[i] = array[i];
    delete[] array;
    array = newArr;
}

template<class T>
void Bag<T>::ShowProperties() {
    cout << "\nShowing properties: " << endl;
    cout << "-------------------------------------" << endl;
    cout << "Size: " << size << endl;
    cout << "Capacity: " << capacity << endl;
    cout << "items: " << endl;
    Print();
    cout << "-------------------------------------" << endl;
}






#endif