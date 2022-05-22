#include <iostream>
#include "MaxHeap.h"
#include "MinHeap.h"
using namespace std;

int main()
{
    int maxArray[13] = {50, 5, 30, 40, 80, 35, 2, 20, 15, 60, 70, 8, 10};
    int minArray[13] = {50, 5, 30, 40, 80, 35, 2, 20, 15, 60, 70, 8, 10};
    MaxHeap<int> maxHeap(1);
    MaxHeap<int> bottomUpMaxheap(1);
    MinHeap<int> minHeap(1);
    MinHeap<int> bottomUpMinheap(1);

    int num;
    int e;
    cout << "Enter the size of sequence: ";
    cin >> num;
    cout << "Enter the sequence: ";
    while (num--) {
        cin >> e;
        maxHeap.Push(e);
        minHeap.Push(e);
    }
    bottomUpMaxheap.bottumUpInitialization(maxArray, 13);
    bottomUpMinheap.bottumUpInitialization(minArray, 13);

    cout << endl;
    cout << "-----testbench for maxHeap-----" << endl;
    cout << "Test for Isempty(): " << maxHeap.Isempty() << endl;
    cout << "Use the level order to display 13 individual pushes maxHeap: "; maxHeap.LevelOrder();
    cout << "MaxHeap.Top(): " << maxHeap.Top() << endl;
    maxHeap.Pop();
    cout << "after MaxHeap.Pop(), MaxHeap.LevelOrder(): "; maxHeap.LevelOrder();
    cout << "Use the level order to display the bottom-up initialization maxHeap: "; bottomUpMaxheap.LevelOrder(); 

    cout << endl;
    cout << "-----testbench for minHeap-----" << endl;
    cout << "Test for Isempty():  " << minHeap.Isempty() << endl;
    cout << "Use the level order to display 13 individual pushes minHeap: "; minHeap.LevelOrder();
    cout << "MinHeap.Top(): " << minHeap.Top() << endl;
    minHeap.Pop();
    cout << "after MinHeap.Pop(), MinHeap.LevelOrder(): "; minHeap.LevelOrder();
    cout << "Use the level order to display the bottom-up initialization minHeap: "; bottomUpMinheap.LevelOrder(); 

    cout << "\n end" << endl;
    return 0;
}