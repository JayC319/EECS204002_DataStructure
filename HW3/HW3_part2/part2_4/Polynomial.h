#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>
#include <math.h>
using namespace std;

template <class T> class Node;
template <class T> class Chain;
class Polynomial;

typedef struct {
    double coef;
    int exp;
}Term;

template <class T>
class Node {
    friend class Chain<T>;
    friend class Polynomial;
public:
    Node() {link = NULL;}
    ~Node(){}
    friend istream& operator>>(istream& is, Polynomial& x);
    friend ostream& operator<<(ostream& os, Polynomial& x);
private:
    T data;
    Node<T>* link;
};



template<class T>
class Chain {
    friend class Polynomial;
public:
    Chain() {head = new Node<T>; head->link = head;}
    ~Chain() {}
    void insertBack(Node<T>* newNode);
    void insertFront(Node<T>* newNode);
    void insertBeforeK(Node<T>* newNode, int k);
    Node<T>* popFront();
    bool isEmpty();
    friend istream& operator>>(istream& is, Polynomial& x);
    friend ostream& operator<<(ostream& os, Polynomial& x);
private:
    Node<T>* head;
};



class Polynomial {
public:
    static Chain<Term> availableNodePool;

    Polynomial() {newPool();}
    Polynomial(const Polynomial&);
    ~Polynomial();
    void newPool();
    Node<Term>* getNode();
    void returnNode(Node<Term>* inNode);
    Polynomial& operator=(const Polynomial& );
    Polynomial operator+(const Polynomial& b) const;
    Polynomial operator-(const Polynomial& b) const;
    Polynomial operator*(const Polynomial& b) const;
    double evaluate(double x) const;
    friend istream& operator>>(istream& is, Polynomial& x);
    friend ostream& operator<<(ostream& os, Polynomial& x);
private:
    Chain<Term> polynomial;    
};

Chain<Term> Polynomial::availableNodePool;






/* Chain class method */
template <class T>
void Chain<T>::insertBack(Node<T>* newNode) {
    if(isEmpty()) {
       head->link = newNode;
       newNode->link = head; 
    }

    else {
        Node<T>* cur = head->link;
        while(cur->link != head) {
            cur = cur->link;
        }
        cur->link = newNode;
        newNode->link = head;
    }
}


template <class T>
void Chain<T>::insertFront(Node<T>* newNode) {
    if(isEmpty()) {
       head->link = newNode;
       newNode->link = head; 
    }

    else {
        newNode->link = head->link;
        head->link = newNode;
    }
}


template<class T>
void Chain<T>::insertBeforeK(Node<T>* newNode, int k) {
    if(k == 1) {
        insertFront(newNode);
    }

    else {
        int count = 1;
        Node<T>* cur = this->head->link;
        while(count < k - 1) {
            cur = cur->link;
        }

        newNode->link = cur->link;
        cur->link = newNode;
    }
}


/**/
template <class T>
Node<T>* Chain<T>::popFront() {
    if(isEmpty()) {
        cerr << "The Chain is empty";
    }
    
    Node<T>* popNode = head->link;
    head->link = popNode->link;
    popNode->link = NULL;
    return popNode;
}


/**/
template <class T>
bool Chain<T>::isEmpty() {
    return head->link == head;
}


/*******************************************************************************************************************************/
/*getNode*/
Node<Term>* Polynomial::getNode() {
    if(availableNodePool.isEmpty())
        newPool();
    Node<Term>* givenNode = availableNodePool.head->link;
    availableNodePool.head->link = givenNode->link;
    givenNode->link = NULL;
    return givenNode;
}


/*returnNode*/
void Polynomial::returnNode(Node<Term>* returnNode) {
    returnNode->link = availableNodePool.head->link;
    availableNodePool.head->link = returnNode;
}


/*creates an availavle Node Pool*/
void Polynomial::newPool() {
    Node<Term>* cur = availableNodePool.head;
    for(int i = 1; i <= 5; i++) {
        Node<Term>* newNode = new Node<Term>;
        cur->link = newNode;
        cur = cur->link;
    }
    cur->link = availableNodePool.head;
}

//(a)
istream& operator>>(istream& is, Polynomial& x) {
    int count;
    cin >> count;
    while(count --) {
        Node<Term>* newNode = x.getNode();
        is >> newNode->data.coef >> newNode->data.exp;
        Node<Term>* cur = x.polynomial.head->link;
        if(cur == x.polynomial.head)
            x.polynomial.insertBack(newNode);
        else if(cur->data.exp < newNode->data.exp)
            x.polynomial.insertFront(newNode);
        else {
            int count = 1;
            
            while(cur != x.polynomial.head) {
                if(cur->data.exp == newNode->data.exp) {
                    cur->data.coef += newNode->data.coef;
                    break;
                }

                if(cur->data.exp < newNode->data.exp) {
                    x.polynomial.insertBeforeK(newNode,count);
                    break;
                }
                count ++;
                cur = cur->link;
            }

            if (cur == x.polynomial.head)
                x.polynomial.insertBack(newNode);
        }
    }
    return is;
}

//(b)
ostream& operator<<(ostream& os, Polynomial& x)
{
    if (x.polynomial.isEmpty())
        os << "{ 0, zero polynomial }";
    else {
        int n = 0;
        Node<Term>* cur;

        cur = x.polynomial.head;
        while (cur->link != x.polynomial.head) {
            n++;
            cur = cur->link;
        }
       
        cur = x.polynomial.head->link;
        while (cur->link != x.polynomial.head) {
            
            if(cur->data.coef > 0)
                os << cur->data.coef << "X^" << cur->data.exp;         
            else
                os << " - " << -cur->data.coef << "X^" << cur->data.exp;
            cur = cur->link;

            if(cur->data.coef > 0)
                os << " + ";
        }
    if(cur->data.coef > 0)
        os << cur->data.coef << "X^" << cur->data.exp;         
    else
        os << " - " << -cur->data.coef << "X^" << cur->data.exp;
    }
    return os;
}


/* (e) destructor */
Polynomial::~Polynomial() {
    while (!polynomial.isEmpty()) {
        returnNode(polynomial.popFront());
    }
}


/* (c) copy constructor */
Polynomial::Polynomial(const Polynomial& p) {
    
    Node<Term>* cur = polynomial.head;
    Node<Term>* pCur = p.polynomial.head->link;

    while(pCur != p.polynomial.head) {
        Node<Term>* newNode = getNode();
        newNode->data.coef = pCur->data.coef;
        newNode->data.exp = pCur->data.exp;
        cur->link = newNode;
        cur = cur->link;
        pCur = pCur->link;
    }
    cur->link = polynomial.head;
}


/* (d) assignment operator */
Polynomial& Polynomial::operator=(const Polynomial& a) {
    while(!polynomial.isEmpty()) {
        returnNode(polynomial.popFront());
    }

    Node<Term>* cur = polynomial.head;
    Node<Term>* aCur = a.polynomial.head->link;
    while (aCur != a.polynomial.head) {
        Node<Term>* newNode = getNode();
        newNode->data.coef = aCur->data.coef;
        newNode->data.exp = aCur->data.exp;
        cur->link = newNode;
        cur = cur->link;
        aCur = aCur->link;
    }
    cur->link = polynomial.head;
    return *this;
}


/* (f) plus operator */
Polynomial Polynomial::operator+(const Polynomial& b) const {
    Polynomial sumPoly;
    Node<Term>* cur = polynomial.head->link;
    Node<Term>* bCur = b.polynomial.head->link;

    while ((cur != polynomial.head) && (bCur != b.polynomial.head)) {
        if(cur->data.exp == bCur->data.exp) {
            Node<Term>* newNode = sumPoly.getNode();
            newNode->data.coef = cur->data.coef + bCur->data.coef;
            newNode->data.exp = cur->data.exp;
            sumPoly.polynomial.insertBack(newNode);
            cur = cur->link;
            bCur = bCur->link;
        }

        else if(cur->data.exp > bCur->data.exp) {
            Node<Term>* newNode = sumPoly.getNode();
            newNode->data.coef = cur->data.coef;
            newNode->data.exp = cur->data.exp;
            sumPoly.polynomial.insertBack(newNode);
            cur = cur->link;
        }

        else {
            Node<Term>* newNode = sumPoly.getNode();
            newNode->data.coef = bCur->data.coef;
            newNode->data.exp = bCur->data.exp;
            sumPoly.polynomial.insertBack(newNode);
            bCur = bCur->link;
        }
    }

    while (cur != polynomial.head) {
        Node<Term>* newNode = sumPoly.getNode();
        newNode->data.coef = cur->data.coef;
        newNode->data.exp = cur->data.exp;
        sumPoly.polynomial.insertBack(newNode);
        cur = cur->link;
    } 

    while(bCur != b.polynomial.head) {
        Node<Term>* newNode = sumPoly.getNode();
        newNode->data.coef = bCur->data.coef;
        newNode->data.exp = bCur->data.exp;
        sumPoly.polynomial.insertBack(newNode);
        bCur = bCur->link;
    }

    return sumPoly;
}


/* (g) minus operator */
Polynomial Polynomial::operator-(const Polynomial& b) const {
    Polynomial resPoly;
    Node<Term>* cur = polynomial.head->link;
    Node<Term>* bCur = b.polynomial.head->link;

    while( cur != polynomial.head && bCur != b.polynomial.head) {
        if(cur->data.exp == bCur->data.exp) {
            Node<Term>* newNode = resPoly.getNode();
            newNode->data.coef = cur->data.coef - bCur->data.coef;
            newNode->data.exp = cur->data.exp;
            resPoly.polynomial.insertBack(newNode);
            cur = cur->link;
            bCur = bCur->link;
        }

        else if (cur->data.exp > bCur->data.exp) {
            Node<Term>* newNode = resPoly.getNode();
            newNode->data.coef = cur->data.coef;
            newNode->data.exp = cur->data.exp;
            resPoly.polynomial.insertBack(newNode);
            cur = cur->link;
        }

        else {
            Node<Term>* newNode = resPoly.getNode();
            newNode->data.coef = -bCur->data.coef;
            newNode->data.exp = bCur->data.exp;
            resPoly.polynomial.insertBack(newNode);
            bCur = bCur->link;
        }
    }

    while (cur != polynomial.head) {
            Node<Term>* newNode = resPoly.getNode();
            newNode->data.coef = cur->data.coef;
            newNode->data.exp = cur->data.exp;
            resPoly.polynomial.insertBack(newNode);
            cur = cur->link;
        }
        

    while(bCur != b.polynomial.head) {
        Node<Term>* newNode = resPoly.getNode();
        newNode->data.coef = -bCur->data.coef;
        newNode->data.exp = bCur->data.exp;
        resPoly.polynomial.insertBack(newNode);
        bCur = bCur->link;
    }

    return resPoly;
}

/* (h) multiply operator */
Polynomial Polynomial::operator*(const Polynomial& b) const {

    Polynomial multPoly;
    Node<Term>* cur = polynomial.head->link;
    Node<Term>* bCur;

    while (cur != polynomial.head) {
        Polynomial tempSumPoly;
        bCur = b.polynomial.head->link;
        while(bCur != b.polynomial.head) {
            Node<Term>* newNode = tempSumPoly.getNode();
            newNode->data.coef = cur->data.coef * bCur->data.coef;
            newNode->data.exp = cur->data.exp * bCur->data.exp;
            tempSumPoly.polynomial.insertBack(newNode);
            bCur = bCur->link;
        }
        multPoly  = multPoly + tempSumPoly;
        cur = cur->link;
    }
    return multPoly;
}

/* (i) evaluate */

double Polynomial::evaluate(double x) const {
    double returnValue = 0;
    Node<Term>* cur = polynomial.head->link;
    while (cur != polynomial.head) {
        returnValue += cur->data.coef * pow(x, cur->data.exp);
        cur = cur->link;
    }
    return returnValue;
}


#endif