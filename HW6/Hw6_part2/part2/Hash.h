#ifndef HASH_H
#define HASH_H
#define VECTOR_DIMENSION 26
#include <iostream>

using namespace std;


struct Node {
    string key;
    struct Node *link;
};
typedef struct Node node;


class ProbingHash {
    public:
        ProbingHash();
        int hash(string e);
        void display();
        void insert(string e);
        string* search(string e);
    
    private:
        string *bucket;
};


class ChainingHash {
    public:
        ChainingHash();
        int hash(string e);
        void display();
        void insert(string e);
        string* search(string e);
    
    private:
        node *bucket;
};

#endif