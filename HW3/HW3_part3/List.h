#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;

template <class T> class Node;
template <class T> class List;


template <class T>
class Node {
    friend class List<T>;    
public:
    Node() {
        data = 0;
        link = NULL;
    }
    ~Node() {
        link = NULL;
    };
    T getData() {return data;}
    Node<T>* getLink() {return link;}
private:
    T data;
    Node<T>* link;
    
};

template <class T>
class List
{
public:
    
    List() {first = NULL;}
    ~List();
    void Display();
    int Size();
    void InsertFront(T);
    void InsertBack(T);
    void DeleteFront();
    void DeleteBack();

    T specialMult();
    T Front();
    T Back();
    T Get(int i);
    void Delete(int i);
    void Insert(int i, T e);
    void Clear();
    template<class K>
    friend ostream& operator<<(ostream& os, List<K>& list);

    class Iterator {
    public:

        Iterator(Node<T>* startNode = NULL) {current = startNode;}

        T& operator*() const {return current->data;}
        T* operator->() const {return &(current->data);}

        Iterator& operator++() {
            current = current->link;
            return *this;
        }

        Iterator operator++(int) {
            Iterator old = *this;
            current = current->link;
            return old;
        }

        bool operator!=(const Iterator r) {return current != r.current;}
        bool operator==(const Iterator r) {return current == r.current;}
        bool hasNext() {return current->link != NULL;}
        
        void add(T newData) {
            Node<T>* newNode = new Node<T>;
            newNode->data = newData;
            newNode->link = NULL;
            current->link = newNode;
        }
        
    
    private:
        Node<T>* current;
    };

    Iterator Begin() {
        Iterator iter(first);
        if (!first)
            cerr << "Empty list";
        return iter;
    }

    Iterator End() {
        Iterator iter(first);
        if(!first)
            cerr << "Empty list";
        Node<T>* cur = first;
        while(cur) {
            cur = cur->link;
            iter++;
        }
        return iter;
    }
private:
    Node<T>* first;
};

/***************************************************/
/*destructor*/
template<class T>
List<T>::~List(){
    Node<T>* deleteNode;
    while(first) {
        deleteNode = first;
        first = first->link;
        delete deleteNode;
    }
}

/**/
template <class T>
int List<T>::Size() {
    int count = 0;
    for(List<T>::Iterator i = Begin(); i != End(); i++) {
        count ++;
    } 
    return count;
}

/*Get*/
template <class T>
T List<T>::Get(int k) {
    int count = 1;
    List<T>::Iterator i = Begin();
    while(i.hasNext() && count < k) {
        i++;
        count++;
    }

    if(count < k)
        cerr << "given index unattainable";
    return *i;
}


/*Display*/
template <class T>
void List<T>::Display() {
    for(List<T>::Iterator i = Begin(); i != End(); i++) {
        cout << *i << " ";
    }
}


/*Front*/
template <class T>
T List<T>::Front() {
    if(!first)
        cerr << "The list is empty"; 
    return first->data;
}


/*Back*/
template <class T>
T List<T>::Back() {
    if(!first)
        cerr << "The list is empty";
    List<T>::Iterator i = Begin();
    while(i.hasNext())
        i++;
    return *i;
}


/*InsertFront*/
template <class T>
void List<T>::InsertFront(T newData) {
    Node<T>* newNode = new Node<T>;
    newNode->data = newData;
    newNode->link = first;
    first = newNode;
}


/*InsertBack*/
template <class T>
void List<T>::InsertBack(T newData) {
    List<T>::Iterator i = Begin();
    
    while(i.hasNext()) 
        i++;
    i.add(newData);
}

/*deleteFront*/
template <class T>
void List<T>::DeleteFront() {
    if(!first)
        return;
    Node<T>* deleteNode = first;
    first = first->link;
    delete deleteNode;
}


/*deleteBack*/
template <class T>
void List<T>::DeleteBack() {
    if(!first)
        return;
    if(!first->link) {
        DeleteFront();
    }

    Node<T>* cur = first;
    while(cur->link->link) {
        cur = cur->link;
    }
    Node<T>* deleteNode = cur->link;
    cur->link = NULL;
    delete deleteNode;
}


/*Delete*/
template <class T>
void List<T>::Delete(int k) {
    if(!first)
        cerr << "empty list" << endl;
    Node<T>* cur = first;
    int count = 1;
    while(cur) {
        if(count == (k - 1)) {
            Node<T>* deleteNode = cur->link;
            cur->link = cur->link->link;
            delete deleteNode;
            return;    
        }
        cur = cur->link;
        count++;
    }
    cerr << "given index unattainable";
}
/*Insert*/
template <class T>
void List<T>::Insert(int k, T newdata) {
    if(!first)
        cerr << "empty list" << endl;
    Node<T>* cur = first;
    
    int count = 1;
    while(cur) {
        if(count == (k - 1)) {
            Node<T>* newNode = new Node<T>;
            newNode->data = newdata;
            newNode->link = cur->link;
            cur->link = newNode;
            return;
        }
        cur = cur->link;
        count++;
    }
    cerr << "given index unattainable";
}



template<class T>
T List<T>::specialMult() {
    if(Size() < 5)
        cerr << "List element less than 5";
    List<T>::Iterator i_5 = Begin();
    T summation = 0;
    for(int i = 0 ; i < 4; i++) 
        i_5++;
    for(List<T>::Iterator i = Begin(); i_5 != End();i++, i_5++) {
        summation += (*i) * (*i_5);
    }
    return summation; 
}


template<class T>
ostream& operator<<(ostream& os, List<T>& list)
{
    list.Display();
    return os;
}


#endif










