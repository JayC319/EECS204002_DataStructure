#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <iomanip>
#include <queue>
#include <stack>
using namespace std;

template <class T> class BinaryTree;
template <class T> class TreeNode;

template <class T>
class TreeNode
{
    friend class BinaryTree<T>;
    public:
        TreeNode();
        TreeNode(T theData, TreeNode<T>* theLeftChild, TreeNode<T>* theRightChild);
        ~TreeNode();
        void SetData(T theData) {data = theData;}
        void SetLeftChild(TreeNode<T>* theLeftChild) {leftChild = theLeftChild;}
        void SetRightChild(TreeNode<T>* theRightChild) {rightChild = theRightChild;}
    private:
        T data;
        TreeNode<T>* leftChild;
        TreeNode<T>* rightChild;
};

template <class T>
class BinaryTree
{
    public:
        BinaryTree(T theData, BinaryTree<T>* leftSubtree, BinaryTree<T>* rightSubtree);
        BinaryTree(const BinaryTree<T>& s);
        BinaryTree(TreeNode<T>* n);
        ~BinaryTree();
        bool Isempty() {return !(root);}
        T RootData() {return root->data;}
        BinaryTree<T>* LeftSubtree() {return new BinaryTree<T>(root->leftChild);}
        BinaryTree<T>* RightSubtree() {return new BinaryTree<T>(root->rightChild);}
        TreeNode<T>* Copy(TreeNode<T>* origNode);
        bool Equal(TreeNode<T>* a, TreeNode<T>* b);
        void Visit(TreeNode<T>* currentNode);
        void Inorder();                           // Inorder driver
        void Inorder(TreeNode<T>* currentNode);   // Inorder workhorse
        void Preorder();                          // Preorder driver
        void Preorder(TreeNode<T>* currentNode);  // Preorder workhorse
        void Postorder();                         // Postorder driver
        void Postorder(TreeNode<T>* currentNode); // Postrder workhorse
        void Levelorder();
        void NonrecInorder();
        void NonstackInorder();
        bool operator==(const BinaryTree<T>& t);

    private:
        TreeNode<T>* root;
};

template <class T>
TreeNode<T>::TreeNode()
{
    leftChild = NULL;
    rightChild = NULL;
}

template <class T>
TreeNode<T>::TreeNode(T theData, TreeNode<T>* theLeftChild, TreeNode<T>* theRightChild)
{
    data = theData;
    leftChild = theLeftChild;
    rightChild = theRightChild;
}

template <class T>
TreeNode<T>::~TreeNode()
{
    leftChild = NULL;
    rightChild = NULL;
}

template <class T>
BinaryTree<T>::BinaryTree(T theData, BinaryTree<T>* leftSubtree, BinaryTree<T>* rightSubtree)
{
    root = new TreeNode<T>;

    root->data = theData;

    if (leftSubtree) root->leftChild = leftSubtree->root;
    else root->leftChild = NULL;

    if (rightSubtree) root->rightChild = rightSubtree->root;
    else root->rightChild = NULL;
}

template <class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T>& s) {
    root = Copy(s.root);
}

template <class T>
BinaryTree<T>::BinaryTree(TreeNode<T>* n) {
    root = n;
}

template <class T>
BinaryTree<T>::~BinaryTree()
{
    root->leftChild = NULL;
    root->rightChild = NULL;
}

template <class T>
TreeNode<T>* BinaryTree<T>::Copy(TreeNode<T>* origNode)
{
    if (!origNode) return NULL;
    else return new TreeNode<T>(origNode->data, Copy(origNode->leftChild), Copy(origNode->rightChild));
}

template <class T>
bool BinaryTree<T>::Equal(TreeNode<T>* a, TreeNode<T>* b)
{
    if ((!a) && (!b)) return true;
    else return (a && b
                && (a->data == b->data)
                && Equal(a->leftChild, b->leftChild)
                && Equal(a->rightChild, b->rightChild));
}

template <class T>
void BinaryTree<T>::Visit(TreeNode<T>* currentNode)
{
    cout << (currentNode->data) << " ";
}

template <class T>
void BinaryTree<T>::Inorder()
{
    Inorder(root);
    cout << endl;
}

template <class T>
void BinaryTree<T>::Inorder(TreeNode<T>* currentNode)
{
    if (currentNode) {
        Inorder(currentNode->leftChild); // L
        Visit(currentNode);              // V
        Inorder(currentNode->rightChild);// R
    }
}

template <class T>
void BinaryTree<T>::Preorder()
{
    Preorder(root);
    cout << endl;
}

template <class T>
void BinaryTree<T>::Preorder(TreeNode<T>* currentNode)
{
    if (currentNode) {
        Visit(currentNode);               // V
        Preorder(currentNode->leftChild); // L
        Preorder(currentNode->rightChild);// R
    }
}

template <class T>
void BinaryTree<T>::Postorder()
{
    Postorder(root);
    cout << endl;
}

template <class T>
void BinaryTree<T>::Postorder(TreeNode<T>* currentNode)
{
    if (currentNode) {
        Postorder(currentNode->leftChild); // L
        Postorder(currentNode->rightChild);// R
        Visit(currentNode);                // V
    }
}

template <class T>
void BinaryTree<T>::Levelorder()
{
    queue<TreeNode<T>*> q;
    TreeNode<T>* currentNode = root;

    while (currentNode) {
        Visit(currentNode);
        if (currentNode->leftChild) q.push(currentNode->leftChild);
        if (currentNode->rightChild) q.push(currentNode->rightChild);

        if (q.empty()) {
            cout << endl;
            return;
        }
        currentNode = q.front();
        q.pop();
    }
}

template <class T>
void BinaryTree<T>::NonrecInorder()
{
    stack<TreeNode<T>*> s;
    TreeNode<T>* currentNode = root;

    while (true) {
        while (currentNode) {
            s.push(currentNode);
            currentNode = currentNode->leftChild;
        }

        if (s.empty()) {
            cout << endl;
            return;
        }
        currentNode = s.top();
        s.pop();
        Visit(currentNode);
        currentNode = currentNode->rightChild;
    }
}

template <class T>
void BinaryTree<T>::NonstackInorder()
{
    if (!root) return;
    TreeNode<T>* top = NULL;
    TreeNode<T>* lastRight = NULL;
    TreeNode<T> *p, *q, *r, *r1;
    p = q = root;

    while (true) {
        while (true) {
            if ((!p->leftChild) && (!p->rightChild)) {
                Visit(p);
                break;
            }
            else if (!p->leftChild) {
                Visit(p);
                r = p->rightChild;
                p->rightChild = q;
                q = p;
                p = r;
            }
            else {
                r = p->leftChild;
                p->leftChild = q;
                q = p;
                p = r;
            }
        }

        TreeNode<T>* av = p;
        while (true) {
            if (p == root) {
                cout << endl;
                return;
            }
            if (!q->leftChild) {
                r = q->rightChild;
                q->rightChild = p;
                p = q;
                q = r;
            }
            else if (!q->rightChild) {
                r = q->leftChild;
                q->leftChild = p;
                p = q;
                q = r;
                Visit(p);
            }
            else {
                if (q == lastRight) {
                    r = top;
                    lastRight = r->leftChild;
                    top = r->rightChild;
                    r->leftChild = r->rightChild = NULL;
                    r = q->rightChild;
                    q->rightChild = p;
                    p = q;
                    q = r;
                }
                else {
                    Visit(q);
                    av->leftChild = lastRight;
                    av->rightChild = top;
                    top = av;
                    lastRight = q;
                    r = q->leftChild;
                    q->leftChild = p;
                    r1 = q->rightChild;
                    q->rightChild = r;
                    p = r1;
                    break;
                }
            }
        }
    }
}

template <class T>
bool BinaryTree<T>::operator==(const BinaryTree<T>& t)
{
    return Equal(root, t.root);
}
#endif // TREE_H