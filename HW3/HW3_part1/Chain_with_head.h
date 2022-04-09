#ifndef CHAIN_WITH_HEAD_H
#define CHAIN_WITH_HEAD_H
#include <iostream>
using namespace std;

template <class T> class Chain;

template <class T>
class ChainNode {
    friend class Chain<T>;
private:
    T data;
    ChainNode<T>* link;
};

template<class T>
class Chain {
public:
    Chain();
    ~Chain();

    void InsertBack(const T&);
    void display();

    int Size();
    void ReplaceNode(int T&);
    void deleteAllOddNode();
    void divideMid(Chain<T>*);
    Chain<T>* deconcatenate(int k);
    Chain<T>* merge(Chain<T>*);
private:
    ChainNode<T>* first;
    ChainNode<T>* head;

};


#endif