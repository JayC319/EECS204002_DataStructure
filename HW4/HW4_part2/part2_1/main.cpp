#include <iostream>
#include "Tree.h"

int main() {


    TreeNode<char> nodesOfA[10];
    TreeNode<char> nodesOfB[10];

    nodesOfA[9].SetData('B');
    nodesOfA[8].SetData('A');
    nodesOfA[7].SetData('C');
    nodesOfA[6].SetData('-');
    nodesOfA[6].SetLeftChild(nodesOfA + 8);
    nodesOfA[6].SetRightChild(nodesOfA + 9);
    nodesOfA[5].SetData('D');
    nodesOfA[4].SetData('*');
    nodesOfA[4].SetLeftChild(nodesOfA + 6);
    nodesOfA[4].SetRightChild(nodesOfA + 7);
    nodesOfA[3].SetData('E');
    nodesOfA[2].SetData('*');
    nodesOfA[2].SetLeftChild(nodesOfA + 4);
    nodesOfA[2].SetRightChild(nodesOfA + 5);
    nodesOfA[1].SetData('+');
    nodesOfA[1].SetLeftChild(nodesOfA + 2);
    nodesOfA[1].SetRightChild(nodesOfA + 3);

    nodesOfB[9].SetData('J');
    nodesOfB[8].SetData('H');
    nodesOfB[7].SetData('G');
    nodesOfB[6].SetData('F');
    nodesOfB[5].SetData('E');
    nodesOfB[4].SetData('D');
    nodesOfB[4].SetLeftChild(nodesOfB + 8);
    nodesOfB[4].SetRightChild(nodesOfB + 9);
    nodesOfB[3].SetData('C');
    nodesOfB[3].SetLeftChild(nodesOfB + 6);
    nodesOfB[3].SetRightChild(nodesOfB + 7);
    nodesOfB[2].SetData('B');
    nodesOfB[2].SetLeftChild(nodesOfB + 4);
    nodesOfB[2].SetRightChild(nodesOfB + 5);
    nodesOfB[1].SetData('A');
    nodesOfB[1].SetLeftChild(nodesOfB + 2);
    nodesOfB[1].SetRightChild(nodesOfB + 3);


    BinaryTree<char> TreeA(nodesOfA + 1);
    BinaryTree<char> CopyA(TreeA);
    BinaryTree<char> TreeB(nodesOfB + 1);
    BinaryTree<char> CopyB(TreeB);


    cout << "----- Testbench for tree A: -----" << endl;
    cout << "Test if Tree A is empty: " << TreeA.Isempty() << endl; 
    cout << "Test For root Data of Tree A: " << TreeA.RootData() << endl;
    cout << "Show left subtree of Tree A in level order: ";
    TreeA.LeftSubtree()->Levelorder();
    cout << "Show right subtree of Tree A in level order: ";
    TreeA.RightSubtree()->Levelorder();
    cout << "Show A in inorder: "; TreeA.Inorder();
    cout << "Show A in preorder: "; TreeA.Preorder();
    cout << "Show A in postorder: "; TreeA.Postorder();
    cout << "Show A in levelorder: "; TreeA.Levelorder();
    cout << "Show A by NonrecInorder: "; TreeA.NonrecInorder();
    cout << "Show A by NonstackInorder: "; TreeA.NonstackInorder();
    cout << "Equality test and compare with the copy constructor" << endl;
    cout << "Is TreeA equal to CopyA: " << ((CopyA == TreeA) ? "Yes\n" : "No\n") << endl;
    cout << endl;


    cout << "----- Testbench for tree B: -----" << endl;
    cout << "Test if Tree B is empty: " << TreeB.Isempty() << endl; 
    cout << "Test For root Data of Tree B: " << TreeB.RootData() << endl;
    cout << "Show left subtree of Tree B in level order: ";
    TreeB.LeftSubtree()->Levelorder();
    cout << "Show right subtree of Tree B in level order: ";
    TreeB.RightSubtree()->Levelorder();
    cout << "Show B in inorder: "; TreeB.Inorder();
    cout << "Show B in preorder: "; TreeB.Preorder();
    cout << "Show B in postorder: "; TreeB.Postorder();
    cout << "Show B in levelorder: "; TreeB.Levelorder();
    cout << "Show B in levelorder: "; CopyB.Levelorder();

    cout << "Show B by NonrecInorder: "; TreeB.NonrecInorder();
    cout << "Show B by NonstackInorder: "; TreeB.NonstackInorder();
    cout << "Equality test and compare with the copy constructor" << endl;
    cout << "Is TreeB equal to CopyB: " << ((CopyB == TreeB) ? "Yes\n" : "No\n") << endl;
    cout << endl;


    cout << "Is TreeB equal to TreeA: " << ((TreeB == TreeA) ? "Yes\n" : "No\n") << endl;
    cout << "end" << endl;
    return 0;


}