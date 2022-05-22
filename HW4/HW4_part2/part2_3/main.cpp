#include <iostream>
#include "BST.h"
using namespace std;

int main() {
    cout << "-----testbench starts -----" << endl;
    BST <int, char> BST1;

    // 50 5 30 40 80 35 2 20 15 60 70 8 10
    int key[13];


    cout << "test for insert of BST" << endl;
    cout << "Enter the number of data: ";
    int num;
    cin >> num;
    cout << "Enter the data: \n";
    for(int i = 1; i <= num; i++) {
        pair<int, char> data;
        cin >> data.first >> data.second;
        BST1.Insert(data);
        key[i] = data.first;
    }

    cout << "\ntest if the BST1 is empty: " << ((BST1.IsEmpty()) ? ("yes") : ("no") ) << endl;

    cout << "\ntest for inorder traversal of BST1: " << endl;
    BST1.Inorder();

    cout << "\n\ntest for RankGet()" << endl;
    for(int i = 0; i < num; i++) {
        cout << "BST1.RankGet(" << i << "): " << BST1.RankGet(i)->first << " " << BST1.RankGet(i)->second << endl;
    }

    cout << "\ntest for Get()" << endl;
    for(int i = 1; i <= num; i++) {
        cout << "BST1.Get(" << key[i] << "): " << BST1.Get(key[i])->second << endl;
    }

    cout << "\ntest for Delete(), I will delete 30 -> 80 -> 40 in the trial" << endl;
    

   BST1.Delete(30);
   BST1.Delete(80);
   BST1.Delete(40);
   cout << "Now the tree through inorder travel: "; 
   BST1.Inorder();

    cout << "\n\ntest for Split(): " << endl;
    BST<int, char> leftSubtree;
    BST<int, char> rightSubtree;
    pair<int, char>* mid;
    BST1.Split(50, leftSubtree, mid, rightSubtree);
    cout << "mid: <" << mid->first << "," << mid->second << ">" << endl;
    cout << "leftSubtree.Inorder(): ";
    leftSubtree.Inorder();
    cout << endl;
    cout << "rightSubtree.Inorder(): ";
    rightSubtree.Inorder();
    cout << endl;

    
    cout << "\nend " << endl;
}