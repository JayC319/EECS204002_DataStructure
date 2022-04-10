#ifndef CHAIN_H
#define CHAIN_H

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
    Chain(){first = 0;}
    ~Chain();

    void InsertBack(const T&);
    void display();

    int Size();
    void ReplaceNode(int, T&);
    void insert(int, T&);
    void deleteAllOddNode();
    void divideMid(Chain<T>*);
    Chain<T>* deconcatenate(int k);
    Chain<T>* merge(Chain<T>*);

private:
    ChainNode<T>* first;
};

//***** ***** ***** funciton declaration ***** ***** *****//
/* destructor */
template <class T>
Chain<T>::~Chain() {
    while(first != NULL) {
        ChainNode<T>* next = first ->link;
        delete first;
        first = next;
    }
}


/* InsertBack */
/**
 * @brief 
 * 
 * @tparam T 
 * @param e 
 */
template <class T>
void Chain<T>::InsertBack(const T& e) {
    if(!first) {
        ChainNode<T>* newNode = new ChainNode<T>;
        newNode->data = e;
        newNode->link = NULL;
        first = newNode;
    } 

    else {
        ChainNode<T>* cur = first;
        while(cur->link) {
            cur = cur->link;
        }
        ChainNode<T>* newNode = new ChainNode<T>;
        newNode->data = e;
        newNode->link = NULL;
        cur->link = newNode;
    }

}


/* display */
/**
 * @brief 
 * 
 * @tparam T 
 */
template <class T>
void Chain<T>::display() {
    if(!first)
        return;
    else {
        ChainNode<T>* cur = first;
        cout << endl;
        while(cur) {
            cout << cur->data << " ";
            cur = cur->link;
        }
    }
}


/* Size */
/**
 * @brief 
 * 
 * @tparam T 
 * @return int 
 */
template<class T>
int Chain<T>::Size() {
    int count = 0;
    ChainNode<T>* cur = this->first;
    if(cur == NULL)                       // if the Chain has no element
        return 0;                                   
    else {
        while (cur != NULL) {             // while the current node is not NULL
            count ++;                     // count increment
            cur = cur->link;
        }           
    }

    return count;
}


/* ReplaceNode */
/**
 * @brief 
 * 
 * @tparam T 
 * @param k 
 * @param newData 
 */
template<class T>
void Chain<T>::ReplaceNode(int k, T& newData) {
    ChainNode<T>* cur = this->first;
    for(int i = 1; i < k; i++) {
        if(cur == NULL)        // indicating that the Chain size is smaller than k
            cerr << "Given index is unattainable" << endl;
        else
            cur = cur->link;
    }
    cur->data = newData;      // update new data
}


/* insert */
/**
 * @brief 
 * 
 * @tparam T 
 * @param k 
 * @param newData 
 */
template <class T>
void Chain<T>::insert(int k, T& newData) {
    ChainNode<T>* cur = this->first;
    ChainNode<T>* newNode = new ChainNode<T>;
    newNode->data = newData;                // initializing a new node
    newNode->link = NULL;                   
    
    for(int i = 1; i < k - 1; i++) {
        if(cur == NULL)                     // Chain size smaller than k
            cerr << "Given index is unattainable";
        else 
            cur = cur->link;
    }
    
    newNode->link = cur->link;              // New node's next node equals to kth node
    cur->link = newNode;                    // k-1 th node's next node is new node.
}


/* deleteAllOddNode */
/**
 * @brief 
 * 
 * @tparam T 
 */
template <class T>
void Chain<T>::deleteAllOddNode() {
    
    if(first) {                    // if the link is not empty
        ChainNode<T>* tempFirst = first; 
        first = first->link;
        delete tempFirst;          // delete the #1 node of the chain

        if(first) {                // if there is more than 1 node in the chain
            ChainNode<T>* evenNode = first;
            ChainNode<T>* oddNode = first->link;

            while (evenNode && oddNode)  // while the #even and #odd node exists
            {
                evenNode->link = oddNode->link; 
                delete oddNode;         

                evenNode = evenNode->link;

                if(evenNode)    // if #even node is not the end of the list
                    oddNode = evenNode->link;
            }       
        }
    }
}


/* divideMid */
/**
 * @brief 
 * 
 * @tparam T 
 * @param subList 
 */
template <class T>
void Chain<T>::divideMid(Chain<T>* subList) {
    int count = this->Size();
    int mid = (count/2 + count%2);  // get mid num from Size

    ChainNode<T>* cur = this->first;

    if(count == 0 || count == 1)    // if size is 0 or 1, then nothing to divide
        return;                                         

    for (int i = 1; i < mid; i++) { // reaches mid node
        cur = cur->link;        
    }

    subList->first = cur->link;     // the sublist starts from the next node of mid node
    cur->link = NULL;

}


/* deconcatenate */
/**
 * @brief 
 * 
 * @tparam T 
 * @param k 
 * @return Chain<T>* 
 */
template <class T>
Chain<T>* Chain<T>::deconcatenate(int k) {
    ChainNode<T>* cur = this->first;
    Chain<T>* newChain = new Chain<T>;
    int count = 0;
    while(cur->link != NULL) {
        if(count == k - 1) {
            newChain->first = cur->link;
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


/* merge */
/**
 * @brief 
 * 
 * @tparam T 
 * @param L2 
 * @return Chain<T>* 
 */
template <class T>
Chain<T>* Chain<T>::merge(Chain<T>* L2) {
    Chain<T>* L3 = new Chain<T>;

    if(!first && !L2->first)    // both chain is empty return empty L3
        return L3;

    if(!first) {             // case of L1 empty
        L3->first = L2->first;
        L2->first = NULL;
        return L3;
    }

    if(!L2->first) {         // case of L2 empty
        L3->first = this->first;
        this->first = NULL;
        return L3;
    }

    ChainNode<T>* N1 = this->first->link;
    ChainNode<T>* N2 = L2->first;
    ChainNode<T>* cur = NULL;
    L3->first = this->first;
    cur = L3->first;

    while(N1 != NULL && N2 != NULL) {  //traverses until reaches one end of the chain
        cur->link = N2;
        cur = cur->link;
        N2 = N2->link;

        cur->link = N1;
        cur = cur->link;
        N1 = N1->link;
    }
   
    if(N1)
        cur->link = N1;   // append the rest of the list to the merged list
    if(N2)
        cur->link = N2;   // append the rest of the list to the merged list
    
    this->first = NULL;  
    L2->first = NULL;
    return L3;+
}

#endif