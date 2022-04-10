#include <iostream>
//#include "Chain.h"
#include "Chain_with_head.h"
//#include "CircularList.h"
#include "CL_with_head.h"

using namespace std;

int main() {
    CircularList<int> CL1;

    for(int i = 0 ; i < 10; i++) {
        CL1.InsertBack(i);
        CL1.InsertFront(i+100);
    }

    Chain <int> C1;

    for(int i = 0; i < 5; i++) 
        C1.InsertBack(i);

    C1.display();
    int j = 666;
    C1.insert(3, j);
    C1.display();


    CL1.display();
    CL1.DeleteFront();

    CL1.display();
    CL1.InsertFront(100);
    CL1.display();
    for(int i = 0; i < 20; i++) 
        CL1.DeleteBack();
    CL1.display();

    cout << "CL1 size: " << CL1.Size() << endl;
    cout << "end" << endl;
    
 
}