#include "CL_with_head.h"

using namespace std;

int main() {
    CircularList<int> CL1;

    cout << "*****testbench start*****" << endl;

    cout << "[test for InsertFront]" << endl;
    for(int i = 0; i< 12; i++) {
        CL1.InsertFront(i);
    }
    CL1.display();

    cout << "\n[test for InsertBack]" << endl;
    for(int i = 0; i< 12; i++) {
        CL1.InsertBack(i*2);
    }
    CL1.display();

    cout << "\n[test for Size() to count the node numbers]" << endl;
    cout << "Size of CL1 is: " << CL1.Size() << endl;

    cout << "\n[test for deleteFront]" << endl;
    cout << "CL1 before deletefront: ";
    CL1.display();
    cout << "CL1 after deletefront 5 times: ";
    for(int i = 0 ; i < 5; i++) {
        CL1.DeleteFront();
    }
    CL1.display();

    cout << "\n[test for deleteBack]" << endl;
    cout << "CL1 before deleteback: ";
    CL1.display();
    cout << "CL1 after deleteback 5 times: ";
    for(int i = 0 ; i < 5; i++) {
        CL1.DeleteBack();
    }
    CL1.display();

    cout << "\n[test for deconcatenate()]" << endl;
    CircularList<int>* CL2;
    CL2 = CL1.deconcatenate(4);
    cout << "CL1: " << endl;
    CL1.display();
    cout << "CL2: " << endl;
    CL2->display();

    cout << "\n[test for deleteAllOddNode()]" << endl;
    cout << "CL2 before delete odd node: " << endl;    
    CL2->display();
    CL2->deleteAllOddNode();
    cout << "CL2 after delete odd node: " << endl;
    CL2->display();

    cout << "\n[test for merge()]" << endl;
    CircularList<int>* mergeList;
    cout << "CL1: ";
    CL1.display();
    cout << "CL2: ";
    CL2->display();
    mergeList = CL1.merge(CL2);
    cout << "mergedlist: ";
    mergeList->display();

    cout << "*****test end*****";
}