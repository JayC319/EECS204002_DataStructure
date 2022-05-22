#ifndef MINHEAP_H
#define MINHEAP_H
#include <iostream>
using namespace std;

template<class T> class MinPQ;
template<class T> class MinHeap;

template<class T>
class MinPQ
{
    public:
        MinPQ() {}
        virtual ~MinPQ(){}
        virtual bool Isempty() const = 0;
        virtual const T& Top() const = 0;
        virtual void Push(const T& x) = 0;
        virtual void Pop() = 0;
};

template<class T>
class MinHeap : public MinPQ<T>
{
    public:
        MinHeap(int thecapacity);
        ~MinHeap();
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
MinHeap<T>::MinHeap(int thecapacity)
{
    if (thecapacity < 1) throw "Capacity must be >= 1.";

    capacity = thecapacity;
    heapSize = 0;
    heap = new T[capacity + 1]; // heap[0] is not used
}

template<class T>
MinHeap<T>::~MinHeap()
{
    delete[] heap;
}

template<class T>
void MinHeap<T>::ChangeSize1D(int newCap)
{
    T* newHeap = new T[newCap + 1];
    for (int i = 1; i <= heapSize; i++) newHeap[i] = heap[i];
    heap = newHeap;
    capacity = newCap;
}

template<class T>
bool MinHeap<T>::Isempty() const
{
    return (heapSize == 0);
}

template<class T>
const T& MinHeap<T>::Top() const
{
    if (Isempty()) 
        throw "Heap is empty.";

    return heap[1];
}

template<class T>
void MinHeap<T>::Push(const T& e)
{
    if (heapSize == capacity) ChangeSize1D(2 * capacity);

    int currentNode = ++heapSize;
    while (currentNode != 1 && heap[currentNode / 2] > e) {
        heap[currentNode] = heap[currentNode / 2];
        currentNode /= 2;
    }
    heap[currentNode] = e;
}

template<class T>
void MinHeap<T>::Pop()
{
    if (Isempty()) 
        throw "Heap is empty.";

    heap[1].~T();
    T lastE = heap[heapSize--];
    int currentNode = 1;       
    int child = 2;       // a child of currentNode
    while (child <= heapSize) {
        // set child to smaller child of currentNode
        if (child < heapSize && heap[child] > heap[child + 1]) child++;

        // check if LastE can be put int currentNode
        if (lastE <= heap[child]) break; // Yes -> break
        else {                           // No  -> go down
            heap[currentNode] = heap[child];
            currentNode = child;
            child *= 2;
        }
    }
    heap[currentNode] = lastE;
}

template<class T>
void MinHeap<T>::LevelOrder()
{
    if (Isempty()) cout << "NULL";
    else {
        for (int i = 1; i <= heapSize; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
}

template<class T>
void MinHeap<T>::bottumUpInitialization(T* arr, int size) {
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
void MinHeap<T>::heapify(T* arr, int n, int i) {
    int smallest = i;
    int l = 2* i + 1;
    int r = 2 * i + 2;

    if(l < n && arr[l] < arr[smallest])
        smallest = l;

    if(r < n && arr[r] < arr[smallest])
        smallest = r;
    
    if(smallest != i) {
        swap(arr[i], arr[smallest]);

        heapify(arr, n, smallest);
    }
}

#endif