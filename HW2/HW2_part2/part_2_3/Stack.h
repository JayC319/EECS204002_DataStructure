#ifndef STACK_H
#define STACK_H
#include "Bag.h"


/* stack class derived from bag*/
template<class T>
class Stack:public Bag<T> {
public:
    Stack(int);
    ~Stack();
    T& Top() const;
    void Pop();
};


template<class T>
Stack<T>::Stack(int stackCapacity):Bag<T>(stackCapacity) {}

template<class T>
Stack<T>::~Stack() {}

/*Top*/
/******************************************************
 * @brief                                             *
 *  returns the top element of the stack if not empty *
 * @tparam T                                          *
 * @return T&                                         *
 ******************************************************/
template<class T>
T& Stack<T>::Top() const {
    if(this->IsEmpty())
        throw "Stack is empty.";
    return this->array[this->top];
}

/*Pop*/
/*****************************************************
 * @brief                                            *
 *  Pops the top element from the stack if not empty *
 * @tparam T                                         *
 *****************************************************/
template<class T>
void Stack<T>::Pop() {
    if(this->IsEmpty())
        throw "Stack is empty";
    this->array[this->top--].~T();
    this->size--;
}




#endif