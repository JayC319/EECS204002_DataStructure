#ifndef CL_WITH_HEAD_H
#define CL_WITH_HEAD_H
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

template <class T>
class CircularList {
public:
    CircularList() {head = new ListNode<T>; head->link = head;}
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
    ListNode<T>* head;
};

/*****************************************************************/
/* destructor */
template <class T>
CircularList<T>::~CircularList() {
    deCircular();
    while(head->link) {
        ListNode<T>* next = head->link;
        delete head;
        head = next;
        
    }
        

    delete head;
}

/* deCircular */
template <class T>
void CircularList<T>::deCircular() {
    ListNode<T>* cur = head;
    if(head->link == head) {
        head->link = NULL;
        return;
    }
        
    while(cur->link != head) {
        cur = cur->link;
    }
    cur->link = NULL;
}

/**/
template <class T>
void CircularList<T>::display() {
    if(head->link == head)
        cout << "empty list" << endl;
    else {
        ListNode<T>* cur = head->link;
        do {
            cout << cur->data << " ";
            cur = cur->link;
        } while(cur != head);
        //cout << "flag" << endl;
    }
    cout << endl;
}




/**/
template <class T>
void CircularList<T>::InsertBack(const T& e) {
    if(head->link == head) {
        ListNode<T>* newNode = new ListNode<T>;
        newNode->data = e;
        newNode->link = head;
        head->link = newNode;
    }

    else {
        ListNode<T>* cur = head->link;
        while(cur->link != head) {
            cur = cur->link;
        }
        ListNode<T>* newNode = new ListNode<T>;
        newNode->data = e;
        newNode->link = head;
        cur->link = newNode;
    }
}

/**/
template <class T>
int CircularList<T>::Size() {
    if(head->link == head)
        return 0;
    int count = 0;
    ListNode<T>* cur = head->link;
    do {
        count ++;
        cur = cur->link;
    }while (cur != head);

    return count;
}

/**/
template <class T>
void CircularList<T>::InsertFront(const T& e) {
    if(head->link == head) {
        ListNode<T>* newNode = new ListNode<T>;
        newNode->data = e;
        newNode->link = head;
        head->link = newNode;
        return;
    }

    ListNode<T>* newNode = new ListNode<T>;
    newNode->link = head->link;
    newNode->data = e;
    head->link = newNode;
}

template <class T>
void CircularList<T>::DeleteFront() {
    if(head->link == head)
        return;
    
    ListNode<T>* deleteNode = head->link;
    head->link = head->link->link;
    delete deleteNode;
}

template <class T>
void CircularList<T>::DeleteBack() {
    if(head->link == head)
        return;
    ListNode<T>* cur = head->link;
    while(cur->link->link != head) {
        cur = cur->link;
    }

    ListNode<T>* deleteNode = cur->link;
    cur->link = NULL;
    deleteNode->link = NULL;

    delete deleteNode;

    if(head->link)
        cur->link = head;

    else 
        head->link = head;
}


/**/
template <class T>
void CircularList<T>::deleteAllOddNode() {
    deCircular();
    if(head->link != head) {
        ListNode<T>* tempFirst = head->link;
        head->link = head->link->link;
        //tempFirst->link = NULL;
        delete tempFirst;

        if(head->link) {
            ListNode<T>* evenNode = head->link;
            ListNode<T>* oddNode = head->link->link;
    
            
            while (evenNode && oddNode )  // while the #even and #odd node exists
            {
                evenNode->link = oddNode->link; 
                delete oddNode;         

                evenNode = evenNode->link;

                if(evenNode)    // if #even node is not the end of the list
                    oddNode = evenNode->link;
            }
            
            ListNode<T>* cur = head;
            while(cur->link) {
                cur = cur->link;
            }
            cur->link = this->head;     
        }
    }
}


/**/
template <class T>
CircularList<T>* CircularList<T>::deconcatenate(int k) {
    if(head->link == head)
        return NULL;
    ListNode<T>* cur = this->head->link;
    CircularList<T>* newCircularList = new CircularList<T>;
    int count = 0;
    while(cur->link != head) {
        if(count == k - 1) {
            newCircularList->head->link = cur->link;
            cur->link = this->head;

            ListNode<T>* sublistCur = newCircularList->head;
            while(sublistCur->link != this->head) {
                sublistCur = sublistCur->link;
            }

            sublistCur->link = newCircularList->head;
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
    if(this->head->link == this->head && CL2->head->link == CL2->head) 
        return CL3;
    if(this->head->link == this->head) {
        CL3->head->link = CL2->head->link;
        CL2->head->link = CL2->head;
        return CL3;
    }

    if(CL2->head->link == CL2->head) {
        CL3->head->link == this->head->link;
        this->head->link = this->head;
        return CL3;
    }

    deCircular();
    CL2->deCircular();

    ListNode<T>* N1 = this->head->link->link;
    ListNode<T>* N2 = CL2->head->link;
    ListNode<T>* cur = NULL;
    CL3->head->link = this->head->link;
    cur = CL3->head->link;

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
        cur->link = CL3->head;
    }

    if(N2) {
        cur->link = N2;
        while (cur->link)
        {
            cur = cur->link;
        }
        cur->link = CL3->head;
    }

    this->head->link = this->head;  
    CL2->head->link = CL2->head;
    return CL3;


}
#endif