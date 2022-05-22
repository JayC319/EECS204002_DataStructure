#ifndef MAXHEAP_H
#define MAXHEAP_H
#include <iostream>
using namespace std;

template<class T> class MaxPQ;
template<class T> class MaxHeap;

template<class T>
class MaxPQ {
public:
    MaxPQ(){}
    virtual ~MaxPQ(){}
    virtual bool Isempty() const = 0;
    virtual const T& Top() const = 0;
    virtual void Push(const T& x) = 0;
    virtual void Pop() = 0;
};

/***************************************************/

template<class T>
class MaxHeap : public MaxPQ<T>
{
    public:
        MaxHeap(int thecapacity) {
            if (thecapacity < 1)
                throw "Capacity must be >= 1";
            capacity = thecapacity;
            heapSize = 0;
            heap = new T[capacity + 1];
        }

        ~MaxHeap();
        void ChangeSize1D(int newCap);
        bool Isempty() const;
        const T& Top() const;
        void Push(const T& e);
        void Pop();
        void LevelOrder();
        void bottumUpInitialization(T*, int size);
        void heapify(T*, int size, int i);
    private:
        T* heap;
        int heapSize;
        int capacity;
};


template<class T>
MaxHeap<T>::~MaxHeap() {
    delete[] heap;
}


template<class T>
void MaxHeap<T>::ChangeSize1D(int newCap) {
    T* newHeap = new T[newCap + 1];
    for(int i = 1; i <= heapSize; i++)
        newHeap[i] = heap[i];
    delete[] heap;
    heap = newHeap;
    capacity = newCap;
}


template <class T>
bool MaxHeap<T>::Isempty() const {
    return (heapSize == 0);
}

template <class T>
const T& MaxHeap<T>::Top() const {
    if(Isempty())
        throw "heap is empty.";
    return heap[1];
}


template<class T>
void MaxHeap<T>::Push(const T& e) {
    if(heapSize == capacity) ChangeSize1D(2 * capacity);

    int currentNode = ++heapSize;
    while(currentNode != 1 && heap[currentNode / 2] < e) {
        heap[currentNode] = heap[currentNode / 2];
        currentNode /= 2;
    }
    heap[currentNode] = e;
}

template<class T>
void MaxHeap<T>::Pop() {
    if(Isempty()) 
        throw "heap is empty";
    heap[1].~T();
    T lastE = heap[heapSize--];
    int currentNode = 1;
    int child = 2;
    while (child <= heapSize) {
        if(child < heapSize && heap[child] < heap[child + 1]) child++;

        if(lastE >= heap[child]) 
            break;
        else {
            heap[currentNode] = heap[child];
            currentNode = child;
            child *= 2;
        }
    }
    heap[currentNode] = lastE;
}


template<class T>
void MaxHeap<T>::LevelOrder() {
    if(Isempty())
        cout << "Empty";
    else {
        for(int i = 1; i <= heapSize; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
}


template<class T>
void MaxHeap<T>::bottumUpInitialization(T* arr, int size) {
    int startIdx = (size / 2) -1;
    heapSize = size;
    ChangeSize1D(size);
    for(int i = startIdx; i>=0; i--) {
        heapify(arr, size, i);
    }

    for(int i = 0; i < size; i++) {
        heap[i + 1] = arr[i];
    }
    
} 


template <class T>
void MaxHeap<T>::heapify(T* arr, int n, int i) {
    int largest = i;
    int l = 2* i + 1;
    int r = 2 * i + 2;

    if(l < n && arr[l] > arr[largest])
        largest = l;

    if(r < n && arr[r] > arr[largest])
        largest = r;
    
    if(largest != i) {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

#endif
