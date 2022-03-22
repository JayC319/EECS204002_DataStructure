#include <iostream>
#include "Queue.h"

using namespace std;
int main() 
{
    cout << "\n[Initializing the first queue, queue1(1, 3, 5, 7)]" << endl;
    Queue <int> queue1(4);
    for(int i = 1; i < 8; i+=2) {
        queue1.Push(i);
    }

    cout << "[Initializing the second queue, queue2(2, 4, 6, 8)]\n" << endl;
    Queue<int> queue2(4);
    for(int i = 2; i < 9; i+=2) {
        queue2.Push(i);
    }

    cout << "\n\n[queue1]:" << endl;
    queue1.ShowProperty();
    cout << "[queue2]:" << endl;
    queue2.ShowProperty();

    

   


    cout << "Reversing both queue1 and queue2" << endl;
    queue1.reverseQueue();
    queue2.reverseQueue();

    cout << "[queue1]:" << endl;
    queue1.ShowProperty();
    cout << "[queue2]:" << endl;
    queue2.ShowProperty();

    cout << "Now we will merge queue2 to queue1 and then reverse queue1" << endl;
    queue1.Merge(queue2);
    cout << "[queue1]: " << endl;
    queue1.ShowProperty();
    queue1.reverseQueue();
    cout << "\n[queue1 after reversed queue]: " << endl;
    queue1.ShowProperty();

    cout << "\nNow we will create a empty queue: queue3\n" << endl;
    Queue<int> queue3(6);
    cout << "Then we will make queue3 the reversed version of queue1\nby using CreateReverseQueue()\n" << endl;
    queue1.CreateReverseQueue(queue3);
    cout << "[queue3]: " << endl;
    queue3.ShowProperty();


}