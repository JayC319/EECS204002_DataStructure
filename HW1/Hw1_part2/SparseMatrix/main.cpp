#include "sparseMatrix.h"
#include <iostream>

int main()
{
    cout << "start of program " << endl << endl;
    
    cout << "input the sparse matrix row and column" << endl;
    int smR, smC;
    cin >> smR >> smC;
    cin.clear();

    SparseMatrix m1(smR, smC, 0);
    
    cout << "Now enter the terms you are going to input, make sure that it is smaller than row * column" << endl;
    int times;
    cin >> times;
    
    cout << "Now initialize your matrix term in the form of (row, column, value)" << endl << endl;
    while(times --) {
        cin >> m1;
        cout << m1 << endl;
    }
    cin.ignore();

    cout << "------------------------------------------" << endl;
    cout << "\nYour Matrix m1 is:" << endl;
    cout << m1 << endl;
    cout << "Also making sure that the term number matches the nonzero entries numbers" << endl;
    cout << "term number: " << m1.getTerm() << endl;
    cout << "------------------------------------------" << endl;


    cout << "\nNow we are creating the tranpose of your matrix m2" << endl;
    SparseMatrix m2 = m1.Transpose();

    cout << "------------------------------------------" << endl;
    cout << "m2 is : " << endl;
    cout << m2 << endl;
    cout << "------------------------------------------" << endl;

    cout << "Exception should be created for invalid addition m1 + m2" << endl;
    cout << "------------------------------------------" << endl;
    SparseMatrix mNew = m1.Add(m2);
    cout << "------------------------------------------" << endl;

    cout << "\nNow we are creating a new matrix by summing your matrix twice" << endl;
    cout << "------------------------------------------" << endl;
    SparseMatrix m3 = m1.Add(m1);
    cout << "The matrix m3 is  " << endl;
    cout << m3 << endl;
    cout << "------------------------------------------" << endl;

    
    cout << "Exception should be created for invalid multiplication m1 * m3" << endl;
    cout << "------------------------------------------" << endl;
    SparseMatrix mmNew = m1.Multiply(m3);
    cout << "------------------------------------------" << endl;
    

    cout << "\nNow we are creating a new matrix by multiplying the traspose m2 to your original matrix" << endl;
    cout << "------------------------------------------" << endl;
    SparseMatrix m4 = m2.Multiply(m1);
    cout << m4 << endl;
    cout << "------------------------------------------" << endl;

    
    cout << "------------------------------------------" << endl;
    cout << "Also making sure that the term number matches the nonzero entries numbers" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "m1:" << endl;
    cout << m1 << endl;
    cout << "m1 term number: " << m1.getTerm() << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "m2:" << endl;
    cout << m2 << endl;
    cout << "m2 term number: " << m2.getTerm() << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "m3:" << endl;
    cout << m3 << endl;
    cout << "m3 term number: " << m3.getTerm() << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "m4:" << endl;
    cout << m4 << endl;
    cout << "m4 term number: " << m4.getTerm() << endl;

    cout << "end of program" << endl;
    return 0;
}