#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H


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

#endif