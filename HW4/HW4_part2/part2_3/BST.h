#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <iostream>
#include <queue>
using namespace std;

template <class K, class E> class BST;
template <class K, class E> class Dictionary;
template <class T> class TreeNode;

template <class K, class E>
class Dictionary
{
    public:
        virtual bool IsEmpty() const = 0;
        virtual pair<K, E>* Get(const K&) const = 0;
        virtual void Insert(const pair<K, E>&) = 0;
        virtual void Delete(const K&) = 0;
};

template <class T>
class TreeNode
{
    public:
        TreeNode();
        TreeNode(T theData);
        ~TreeNode();
        void SetData(T theData) {data = theData;}
        void SetLeftChild(TreeNode<T>* theLeftChild) {leftChild = theLeftChild;}
        void SetRightChild(TreeNode<T>* theRightChild) {rightChild = theRightChild;}

        T data;
        TreeNode* leftChild;
        TreeNode* rightChild;
        int leftSize;
};

template <class K, class E>
class BST : public Dictionary<K, E> {
public:
    BST();
    ~BST();
    bool IsEmpty() const;
    pair<K, E>* Get(const K& k) const;
    pair<K, E>* RankGet(int r) const;
    TreeNode<pair<K, E>>* RankGet(int& r, TreeNode<pair<K, E>>* currentNode) const;
    TreeNode<pair<K, E>>* getMinimumKey(TreeNode<pair<K, E>>* curr);
    void searchKey(TreeNode<pair<K, E>>* &curr, const K& k, TreeNode<pair<K, E>>* & parent);

    void Visit(TreeNode<pair<K, E>>* currentNode) const;
    void Insert(const pair<K, E>&);
    void Delete(const K& k);
   
    void Split(const K& k, BST<K,E>& small, pair<K,E>*& mid, BST<K, E>& big);
    void Inorder() const;                                    // Inorder driver
    void Inorder(TreeNode<pair<K, E>>* currentNode) const;   // Inorder workhorse
private:
    TreeNode<pair<K, E>>* root;
};

/***************************************************************************/
template <class T>
TreeNode<T>::TreeNode() {
    leftChild = NULL;
    rightChild = NULL;
    leftSize = 0;
}

template <class T>
TreeNode<T>::TreeNode(T thedata) {
    data = thedata;
    leftChild = NULL;
    rightChild = NULL;
}


template <class T>
TreeNode<T>::~TreeNode() {
    leftChild = NULL;
    rightChild = NULL;
    leftSize = 0;
}




/**************************************************************************/
template <class K, class E>
BST<K, E>::BST() {
    root = 0;
}


template <class K, class E>
BST<K, E>::~BST() {
    root->leftChild = NULL;
    root->rightChild = NULL;
    delete root;
    root->leftSize = 0;
}


template <class K, class E>
bool BST<K, E>::IsEmpty() const {
    return !root;
}


template <class K, class E>
pair<K, E>* BST<K, E>::Get(const K& k) const {
    TreeNode<pair<K, E>>* currentNode = root;
    while (currentNode) {
        if (k < currentNode->data.first) currentNode = currentNode->leftChild;
        else if (k > currentNode->data.first) currentNode = currentNode->rightChild;
        else return &(currentNode->data);
    }

    cout << "Data doesn't Exist";
    return NULL;
}



template <class K, class E>
void BST<K, E>::searchKey(TreeNode<pair<K, E>>* &curr, const K& k, TreeNode<pair<K, E>>* & parent) {
    while(curr && curr->data.first != k) {
        parent = curr;

        if(k < curr ->data.first) {
            curr = curr->leftChild;
        }
        else {
            curr = curr->rightChild;
        }
    }
}


template <class K, class E>
pair<K, E>* BST<K, E>::RankGet(int r) const {

    TreeNode<pair<K, E>>* target = NULL;
    target = RankGet(r, root);
    return &(target->data);
}


template <class K, class E>
TreeNode<pair<K, E>>* BST<K, E>::RankGet(int& r, TreeNode<pair<K, E>>* currentNode) const
{
    if (currentNode && (r+1)) {
        TreeNode<pair<K, E>>* left = NULL;
        TreeNode<pair<K, E>>* right = NULL;

        left = RankGet(r, currentNode->leftChild);
        if ((--r) == -1) return currentNode;
        right = RankGet(r, currentNode->rightChild);

        if (left) 
            return left;
        else if (right) 
            return right;
    }
    return NULL;
}




template <class K, class E>
TreeNode<pair<K, E>>* BST<K, E>::getMinimumKey(TreeNode<pair<K, E>>* curr) {
    while(curr->leftChild != NULL) {
        curr = curr->leftChild;
    }
    return curr;
}


template <class K, class E>
void BST<K, E>::Visit(TreeNode<pair<K,E>>* currentNode) const {
    cout << "<" << currentNode->data.first << "," << currentNode->data.second << "> ";
}


template <class K, class E>
void BST<K, E>::Inorder() const {
    Inorder(root);
}


template <class K, class E>
void BST<K, E>:: Inorder(TreeNode<pair<K, E>>* currentNode) const {
    if(currentNode) {
        Inorder(currentNode->leftChild);
        Visit(currentNode);
        Inorder(currentNode->rightChild);
    }
}


template <class K, class E>
void BST<K, E>::Insert(const pair<K, E>& thePair) {
    TreeNode<pair<K,E>>* p = root;
    TreeNode<pair<K,E>>* pp = NULL;

    while(p) {
        pp = p;
        if(thePair.first < p->data.first) {
            p->leftSize++;
            p = p->leftChild;
        }

        else if(thePair.first > p->data.first)
            p = p->rightChild;
        
        else {
            p->data.second = thePair.second;
            return;
        }
    }

    p = new TreeNode<pair<K,E>>(thePair);
    p->leftSize = 1;
    if(root) {
        if (thePair.first < pp->data.first)
            pp->leftChild = p;
        else 
            pp->rightChild = p;
    }

    else {
        root = p;
        root->leftSize = 1;
    }
}


template <class K, class E>
void BST<K, E>::Delete(const K& k) {
    
    TreeNode<pair<K,E>>* parent = NULL;
    TreeNode<pair<K,E>>* curr = root;

    searchKey(curr, k, parent);

    if(!curr)
        return;
    if(!curr->leftChild && !curr->rightChild) {
        if(curr != root) {
            if(parent->leftChild == curr)
                parent->leftChild = NULL;
            else 
                parent->rightChild = NULL;
        }
        else {
            root = NULL;
        }

        delete curr;
    }

    else if(curr->leftChild && curr->rightChild) {
        TreeNode<pair<K,E>>* successor = getMinimumKey(curr->rightChild);
        pair<K,E> val = successor->data;

        Delete(val.first);
        curr->data = val;
    }

    else {
        TreeNode<pair<K,E>>* child = (curr->leftChild)? curr->leftChild : curr->rightChild;

        if(curr != root) {
            if(curr == parent->leftChild) {
                parent->leftChild = child;
            }
            else {
                parent->rightChild = child;
            }
        }

        else {
            root = child;
        }

        delete curr;
    }
}





template <class K, class E>
void BST<K, E>::Split(const K& k, BST<K, E>& small, pair<K, E>*& mid, BST<K, E>& big)
{
    if (!root) {
        small.root = big.root = 0;
        return;
    }

    TreeNode<pair<K, E>>* sHead = new TreeNode<pair<K, E>>;
    TreeNode<pair<K, E>>* s = sHead;
    TreeNode<pair<K, E>>* bHead = new TreeNode<pair<K, E>>;
    TreeNode<pair<K, E>>* b = bHead;
    TreeNode<pair<K, E>>* currentNode = root;

    while (currentNode) {
        if (k < currentNode->data.first) {
            b->leftChild = currentNode;
            b = currentNode;
            b->leftSize--;
            currentNode = currentNode->leftChild;
        }
        else if (k > currentNode->data.first) {
            s->rightChild = currentNode;
            s = currentNode;
            currentNode = currentNode->rightChild;
        }
        else {
            s->rightChild = currentNode->leftChild;
            b->leftChild = currentNode->rightChild;
            small.root = sHead->rightChild;
            free(sHead);
            big.root = bHead->leftChild;
            free(bHead);
            mid = new pair<K, E>(currentNode->data.first, currentNode->data.second);
            free(currentNode);
            return;
        }
    }

    s->rightChild = b->leftChild = 0;
    b->leftSize = 1;
    small.root = sHead->rightChild;
    delete sHead;
    big.root = bHead->leftChild;
    delete bHead;
    mid = 0;
    return;
} 


#endif 