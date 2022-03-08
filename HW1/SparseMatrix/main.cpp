#include "sparseMatrix.h"
#include <iostream>

int main()
{
    SparseMatrix m1(5, 5, 1);
    int times = 10;
    
    while(times --) {
        cin >> m1;
        m1.printSparseArray();
        cout << m1 << m1.getTerm() << endl;
    }
    
    
}