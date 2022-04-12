#include "List.h"

#include <iostream>
using namespace std;

int main() {
    List<int> L1;

    for(int i = 0; i < 10; i++) {
        L1.InsertFront(i);
    }

    L1.InsertBack(8);

    cout << L1 << endl;
    cout << "Front: " << L1.Front() << " Back: " << L1.Back() << endl;
    cout << "Get 5th element: " << L1.Get(5) << endl;
    L1.DeleteBack();
    L1.DeleteFront();
    cout << L1 << endl;
    L1.Delete(4);
    cout << L1 << endl;
    L1.Insert(8, 888);
    cout << L1 << endl;
    cout << "\nSize: " << L1.Size() << endl;
    cout << "end" << endl;
    cout << "summation of speical mult: " << L1.specialMult() << endl; 
}


