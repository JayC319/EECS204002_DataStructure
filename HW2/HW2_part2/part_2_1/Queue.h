#ifndef QUEUE_H
#define QUEUE_H

template <class T>
class Queue
{
private:
    T* queue;
    int front,
        rear,
        capacity,
        size;
public:
        //constructor
        Queue(int queueCapacity):capacity(queueCapacity) {
        if(capacity < 1)
                throw "Queue capacity must be 0";
        queue = new T[capacity];
        front = 0;
        rear = 0;
        size = 0;
        }
        //destructor
        ~Queue() {delete []queue; queue = nullptr;}
        
        bool IsEmpty() const;
        void Push(const T&);
        void Pop();
        T& Front() const;
        T& Rear() const;
        int Size() const;
        int Capacity() const;
        void Show();
        void ShowProperty();
        void Merge(Queue<T>& b);
};



#endif