#ifndef QUEUE_H
#define QUEUE_H
#include "Stack.h"


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
        void reverseQueue();
        void CreateReverseQueue(Queue<T>& b);
};

/*reverseQueue()*/
/*******************************************************************************
 *   This class method takes no parameter and simply reverse the current queue *
 *******************************************************************************/
template <class T>
void Queue<T>::reverseQueue() {
        Stack<T> tempStack(size);
        while(!IsEmpty()) {
                tempStack.Push(Front());
                Pop();
        }

        while(!tempStack.IsEmpty()) {
                Push(tempStack.Top());
                tempStack.Pop();
        }
        cout << "\n[The queue has been reversed]\n(This message is from the reverseQueue function)" << endl;
}

/* CreateReverseQueue*/
/*****************************************************************
 * This class method takes an Queue object as parameter and then *
 * make the class object the reversed version of the queue.      *
 *****************************************************************/
template <class T>
void Queue<T>::CreateReverseQueue(Queue<T> &b){
        while(!b.IsEmpty()){
            b.Pop();
        }
        Stack<T> tempStack(size);
        
        for(int i = 1; i <= size; i++) {
                tempStack.Push(queue[(front+i) % Capacity()]);
        }

        while(!tempStack.IsEmpty()) {
                b.Push(tempStack.Top());
                tempStack.Pop();
        }
        
}




#endif