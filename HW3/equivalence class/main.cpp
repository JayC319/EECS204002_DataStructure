#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

void Equivalence();
class Enode {
    friend void Equivalence();
public:
    Enode(int d = 0, Enode* l = NULL) { data = d; link = l;}
private:
    int data;
    Enode* link;
};

void Equivalence() {
    ifstream inFile("equiv.txt");
    if(!inFile) throw "Cannot open file.";
    int i, j, n;
    inFile >> n;

    bool *out = new bool[n];
    Enode** first = new Enode* [n];


    for(int i = 0; i < n; i++) {
        first[i] = NULL;
    }
   

    for(int i = 0; i < n; i++) {
        out[i] = false;
    }

    inFile >> i >> j;
    while(inFile.good()) {
        first[i] = new Enode(j, first[i]);
        first[j] = new Enode(i, first[j]);
        inFile >> i >> j;
    }
    inFile.close();

    for(int count = 0; count < n; count++) {
        Enode* ePtr = first[count];
        while(ePtr)
        {
            cout << ePtr->data << ", ";
            ePtr = ePtr->link;
        }
        cout << "--" << endl;   
    }


    for(int i = 0; i < n; i++) {
        if(!out[i]) {
            cout << endl << "A new class: " << i;
            out[i] = true;
            stack<Enode> s;
            Enode *x = first[i];
            while (true) {
                while (x) {
                    j = x->data;
                    if(!out[j]) {
                        cout << ", " << j;
                        out[j] = true;
                        s.push(*x);
                    }
                    else {
                        x = x->link;
                    }
                }
                if(s.empty())
                    break;
                
                x = first[s.top().data];
                s.pop();
            }
        }
        
    }

    for(i = 0; i < n; i++) {
            while (first[i])
            {
                Enode * delNode = first[i];
                first[i] = delNode->link;
                delete delNode;
            }
        }
        delete [] first;
        delete [] out;
}

int main() {
    Equivalence();
    cout << "\nend" << endl;
}