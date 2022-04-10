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
    Chain() { head = new ChainNode<T>; head->link = head;}
    ~Chain();

    void InsertBack(const T&);
    void display();

    int Size();
    void ReplaceNode(int, T&);
    void insert(int, T&);
    void deleteAllOddNode();
    void divideMid(Chain<T>*);
    Chain<T>* deconcatenate(int);
    Chain<T>* merge(Chain<T>*);
private:
    
    ChainNode<T>* head;
};


/**/
template <class T>
Chain<T>::~Chain() {
    while(head != NULL) {
        ChainNode<T>* next = head->link;
        delete head;
        head = next;
    }
}



/* InsertBack*/
template <class T>
void Chain<T>::InsertBack(const T& e) {

    if(head->link == head) {
        ChainNode<T>* newNode = new ChainNode<T>;
        newNode->data = e;
        newNode->link = NULL;
        head->link = newNode;
    }

    else {
        ChainNode<T>* cur = head->link;
        while(cur->link) {
            cur = cur->link;
        }
        ChainNode<T>* newNode = new ChainNode<T>;
        newNode->data = e;
        newNode->link = NULL;
        cur->link = newNode;
    }
    
}


/**/
template <class T>
void Chain<T>::display() {
    if(head->link == head)
        return;
    else {
        ChainNode<T>* cur = head->link;
        cout << endl;
        while(cur) {
            cout << cur->data << " ";
            cur = cur->link;
        }
    }
}


/**/
template <class T>
int Chain<T>::Size() {
    if(head->link == head)
        return 0;
    int count = 0;
    ChainNode<T>* cur = head->link;
    while(cur) {
        count ++;
        cur = cur->link;
    }

    return count;
}


/**/
template <class T>
void Chain<T>::ReplaceNode(int k, T& newData) {
    ChainNode<T>* cur = head->link;
    for(int i = 1; i < k; i++) {
        if(!cur)
            cerr << "Given index unattainable" << endl;
        else 
            cur = cur->link;
    }
    cur->data = newData;
}

/**/
template <class T>
void Chain<T>::insert(int k , T& newData) {
    ChainNode<T>* cur = head->link;
    ChainNode<T>* newNode = new ChainNode<T>;
    newNode->data= newData;
    newNode->link = NULL;

    for(int i = 1; i < k- 1; i++) {
        if(!cur)
            cerr << "Given index is unattainable";
        else 
            cur = cur->link;
    }

    newNode->link = cur->link;
    cur->link = newNode;
}

/**/
template <class T>
void Chain<T>::deleteAllOddNode() {
    if(head->link) {
        ChainNode<T>* tempFirst = head->link;
        head->link = head->link->link;
        delete tempFirst;
        if(head->link) {
            ChainNode<T>* evenNode = head->link;
            ChainNode<T>* oddNode = head->link->link;


            while(evenNode && oddNode) {
                
                
                evenNode->link = oddNode->link;
                delete oddNode;

                evenNode = evenNode->link;

                if(evenNode)
                    oddNode = evenNode->link;
            }
        }
    }
}


/**/
/* divideMid*/
template <class T>
void Chain<T>::divideMid(Chain<T>* sublist) {
    int count = this->Size();
    int mid = (count/2 + count%2);  // get mid num from Size

    ChainNode<T>* cur = head->link;

    if(count == 0 || count == 1)
        return;
    
    for(int i = 1; i < mid; i++) {
        cur = cur->link;
    }

    sublist->head->link = cur->link;
    cur->link = NULL;

}

/**/
template <class T>
Chain<T>* Chain<T>::deconcatenate(int k) {
    ChainNode<T>* cur = this->head->link;
    Chain<T>* newChain = new Chain<T>;
    int count = 0;

    while(cur->link) {
        if(count == k - 1) {
            newChain->head->link = cur->link;
            cur->link = NULL;
            return newChain;
        }

        else {
            cur = cur->link;
            count ++;
        }
    }

    cerr << "Given index is unattainable." ;
    return NULL;
}

template <class T>
Chain <T>* Chain<T>::merge(Chain<T>* L2) {
    Chain<T>* L3 = new Chain<T>;

    if(!head->link && L2->head->link)
        return L3;
    
    if(!head->link) {
        L3->head->link = L2->head->link;
        L2->head->link = NULL;
        return L3;
    }

    if(!L2->head->link) {
        L3->head->link = this->head->link;
        head->link = NULL;
        return L3;
    }

    ChainNode<T>* N1 = head->link->link;
    ChainNode<T>* N2 = L2->head->link;
    ChainNode<T>* cur = NULL;
    L3->head->link = head->link;
    cur = L3->head->link;


    while (N1 != NULL && N2 != NULL) {
        cur->link = N2;
        cur = cur->link;
        N2 = N2->link;

        cur->link = N1;
        cur = cur->link;
        N1 = N1->link;
    }

    if(N1)
        cur->link = N1;
    if(N2) {
        //cur = cur->link;
        cur->link = N2;
    }
        

    this->head->link = NULL;
    L2->head->link = NULL;
    return L3;
}
#endif