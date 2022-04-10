#ifndef CL_WITH_HEAD_H
#define CL_WITH_HEAD_H

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
private:
    ListNode<T>* head;
};

/*****************************************************************/
/* destructor */
template <class T>
CircularList<T>::~CircularList() {
    deCircular();
    while(head->link) {
        ListNode<T>* next = head->link->link;
        delete head;
        head = next;
    }
}

/* deCircular */
template <class T>
void CircularList<T>::deCircular() {
    ListNode<T>* cur = head->link;
    if(!head->link)
        return;
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
    }
    cout << endl;
}


/**/
template <class T>
void CircularList<T>::InsertBack(const T& e) {
    if(!head->link) {
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
#endif