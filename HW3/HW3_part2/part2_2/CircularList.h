#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H
#include <iostream>
using namespace std;

template <class T> class CircularList;


template <class T>
class ListNode {
    friend class CircularList<T>;
private:
    T data;
    ListNode<T>* link;
};


template<class T>
class CircularList {
public:
    CircularList() {first = 0;}
    ~CircularList();

    void deCircular();
   
    void display();
    

    int Size();
    void InsertFront(const T&);
    void InsertBack(const T&);
    void DeleteFront();
    void DeleteBack();
    void deleteAllOddNode();
    CircularList<T>* deconcatenate(int);
    CircularList<T>* merge(CircularList<T>*);

private:
    ListNode<T>* first;
};


/***************************************************************************/
/* destructor */
template <class T>
CircularList<T>::~CircularList() {
    deCircular();
    while(first != NULL) {
         ListNode<T>* next = first ->link;
         delete first;
         first = next;
    }
}




/* deCircular */
/**
 * @brief 
 * 
 * @tparam T 
 */
template <class T>
void CircularList<T>::deCircular() {
    ListNode<T>* cur = first;
    if(!first)
        return;

    while(cur->link != first) {
        cur = cur->link;
    }

    cur->link = NULL;
    
}


/**/
template<class T>
void CircularList<T>::display() {
    if(!first)
        cout << "empty list" << endl;
    else {
        ListNode<T>* cur = first;
        do {
            cout << cur->data << " ";
            cur = cur->link;
        } while(cur != first);
        
    }
    cout << endl;
}


/**/
template <class T>
void CircularList<T>::InsertBack(const T& e) {
    if(!first) {
        ListNode<T>* newNode = new ListNode<T>;
        newNode->data = e;
        newNode->link = newNode;
        first = newNode;
    }

    else {
        ListNode<T>* cur = first;
        while(cur->link != first) {
            cur = cur->link;
        }
        ListNode<T>* newNode = new ListNode<T>;
        newNode->data = e;
        newNode->link = first;
        cur->link = newNode;
    }
}


/**/
template <class T>
int CircularList<T>::Size() {
    if(!first)
        return 0;
    
    int count = 0;
    ListNode<T>* cur = first;
    do {
        count ++;
        cur = cur->link;
    } while(cur != first);

    return count;
}


/**/
template <class T>
void CircularList<T>::InsertFront(const T& e) {
    if(!first) {
        ListNode<T>* newNode = new ListNode<T>;
        newNode->data = e;
        newNode->link = newNode;
        first = newNode;
        return;
    }

    ListNode<T>* cur = first;

    while(cur->link != first) {
        cur = cur->link;
    }

    ListNode<T>* newNode = new ListNode<T>;
    newNode->data = e;
    newNode->link = first;
    cur->link = newNode;
    first = newNode;     
}


/**/
template <class T>
void CircularList<T>::DeleteFront() {
    if(!first)
        return;                   // return if nothing to delete
    ListNode<T>* cur = first;     // use the ListNode pointer to traverse the list.
    while(cur->link != first) {   // traverse until we reach the last node from first
        cur = cur->link;
    }

    ListNode<T>* deleteNode = cur->link; // assign a pointer to the first node
    cur->link = NULL;                    // let the last node points to NULL
    first = first->link;                 // first now then becomes the next node to first
    delete deleteNode;                   // delete the first node

    if(first)                            // if there is more than one node before delete
        cur->link = first;               // connects the last node to the new first.
}


/**/
template <class T>
void CircularList<T>::DeleteBack() {
    if(!first)
        return;                       // return if nothing to delete
    ListNode<T>* cur = first;         // use the ListNode pointer to traverse the list.
    while(cur->link->link != first) { // traverse until we reach the second last node from first
        cur = cur->link;              
    }

    ListNode<T>* deleteNode = cur->link;    // assign a pointer to the last node 
    cur->link = NULL;                       // let the link to the last node break
    deleteNode->link = NULL;                // let the last node break it's link
    
    if(cur == deleteNode)                   // if there is only one node
        first = NULL;                       // let first points to NULL

    delete deleteNode;                      // delete the last node

    if(first)                               // if there is node in the list
        cur->link = first;                  // link the original second last node back to first node.
}


/**/
template<class T>
void CircularList<T>::deleteAllOddNode() {
    deCircular();
    if(first) {                    // if the link is not empty
        ListNode<T>* tempFirst = first; 
        first = first->link;
        delete tempFirst;          // delete the #1 node of the chain

        if(first) {                // if there is more than 1 node in the chain
            ListNode<T>* evenNode = first;
            ListNode<T>* oddNode = first->link;

            while (evenNode && oddNode)  // while the #even and #odd node exists
            {
                evenNode->link = oddNode->link; 
                delete oddNode;         

                evenNode = evenNode->link;

                if(evenNode)    // if #even node is not the end of the list
                    oddNode = evenNode->link;
            }
            
            ListNode<T>* cur = first;
            while(cur->link) {
                cur = cur->link;
            }
            cur->link = this->first;      
        }
    }
}


/**/
template <class T>
CircularList<T>* CircularList<T>::deconcatenate(int k) {
    if(!first)
        return NULL;
    ListNode<T>* cur = this->first;
    CircularList<T>* newCircularList = new CircularList<T>;
    int count = 0;
    while(cur->link != first) {
        if(count == k - 1) {
            newCircularList->first = cur->link;
            cur->link = this->first;

            ListNode<T>* sublistCur = newCircularList->first;
            while(sublistCur->link != this->first) {
                sublistCur = sublistCur->link;
            }

            //newCircularList->LinkReartoFirst(newCircularList->first);

            sublistCur->link = newCircularList->first;
            return newCircularList;
        }

        else {
            cur = cur->link;
            count++;
        }

    }

    cerr << "Given index is unattainable.";
    return NULL;
}


/**/
template <class T>
CircularList<T>* CircularList<T>::merge(CircularList<T>* CL2) {
    CircularList<T>* CL3 = new CircularList<T>;

    

    if(!first && !CL2->first)
        return CL3;
    
    if(!first) {
        CL3->first = CL2->first;
        CL2->first = NULL;
        return CL3;
    }

    if(!CL2->first) {
        CL3->first = this->first;
        this->first = NULL;
        return CL3;
    }

    deCircular();
    CL2->deCircular();

    ListNode<T>* N1 = this->first->link;
    ListNode<T>* N2 = CL2->first;
    ListNode<T>* cur = NULL;
    CL3->first = this->first;
    cur = CL3->first;

    while(N1 != NULL && N2 != NULL) {
        cur->link = N2;
        cur = cur->link;
        N2 = N2->link;

        cur->link = N1;
        cur = cur->link;
        N1 = N1->link;
    }

    if(N1) {
        cur->link = N1;
        while (cur->link)
        {
            cur = cur->link;
        }
        cur->link = CL3->first;
    }

    if(N2) {
        cur->link = N2;
        while (cur->link)
        {
            cur = cur->link;
        }
        cur->link = CL3->first;
    }
   // cout << "flag" << endl;
    this->first = NULL;  
    CL2->first = NULL;
    return CL3;

}
#endif