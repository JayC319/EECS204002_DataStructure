#include "Hash.h"

ProbingHash::ProbingHash() {
    bucket = new string[VECTOR_DIMENSION];
}


int ProbingHash::hash(string e) {
    int h = int(e[0]) - 97;
    return h;
}


void ProbingHash::display() {
    for(int i = 0; i < VECTOR_DIMENSION; i++)
        cout << "[" << i << "]" << bucket[i] << endl;
}


void ProbingHash::insert(string e) {
    int h = hash(e);
    while (bucket[h] != "") {
        h = (h + 1) % VECTOR_DIMENSION;
    }
    bucket[h] = e;
}


string* ProbingHash::search(string e) {
    int h = hash(e);
    int i = h;
    while(bucket[i] != e) {
        i = (i + 1) % VECTOR_DIMENSION;
        if(i == h) 
            return 0;
    }
    return bucket + i;
}


/**********ChainingHash**********/
ChainingHash::ChainingHash() {
    bucket = new node[VECTOR_DIMENSION];
}


int ChainingHash::hash(string e) {
    int h = int(e[0]) - 97;
    return h;
}


void ChainingHash::display() {
    for(int i = 0; i < VECTOR_DIMENSION; i++) {
        cout << "[" << i << "]";
        for(node *l = bucket[i].link; l != NULL; l = l->link)
            cout << " --> " << l->key;
        
        cout << " --> 0\n";
    }
}


void ChainingHash::insert(string e)
{
    int h = hash(e);
    node *iter;
    node *new_node = new node;
    new_node->key = e;
    new_node->link = 0;

    for (iter = (bucket + h); iter->link != 0; iter = iter->link);
    iter->link = new_node;
}

string* ChainingHash::search(string e)
{
    int h = hash(e);
    for (node *iter = bucket[h].link; iter != 0; iter = iter->link) {
        if (iter->key == e) return &(iter->key);
    }
    return 0;
}