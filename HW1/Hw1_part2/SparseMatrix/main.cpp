#include "sparseMatrix.h"
#include <iostream>

int main()
{
    cout << "start of program " << endl << endl;
    
    cout << "input the sparse matrix row and column" << endl;
    int smR, smC;
    cin >> smR >> smC;


    SparseMatrix m1(smR, smC, 0);
    
    cout << "Now enter the terms you are going to input, make sure that it is smaller than row * column" << endl;
    int times;
    cin >> times;
    
    cout << "Now initialize your matrix term in the form of (row, column, value)" << endl << endl;
    while(times --) {
        cin >> m1;
        //m1.printSparseArray();
        cout << m1 << endl;
    }
    

    cout << "\nYour Matrix m1 is:" << endl;
    cout << m1 << endl;
    cout << "Also making sure that the term number matches the nonzero entries numbers" << endl;
    cout << "term number: " << m1.getTerm() << endl;

    cout << "\nNow we are creating the tranpose of your matrix" << endl;
    SparseMatrix m2 = m1.Transpose();

    cout << "Transpose of your matrix m2 is : " << endl;
    cout << m2 << endl;
    
    
    cout << "\nNow we are creating a new matrix by summing your matrix twice" << endl;
    SparseMatrix m3 = m1.Add(m1);
    cout << "The matrix m3 is  " << endl;
    cout << m3 << endl;

    cout << "\nNow we are creating a new matrix by multiplying the traspose m2 to your original matrix" << endl;
    SparseMatrix m4 = m2.Multiply(m1);
    cout << m4 << endl;

    
    cout << "end of program" << endl;
    return 0;
}