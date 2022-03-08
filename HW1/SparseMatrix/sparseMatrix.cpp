#include "sparseMatrix.h"
#include <iostream>

void SparseMatrix::printSparseArray() {
    for (int i = 0; i < terms; i++ ){
        cout << "   " << smArray[i].getCol();
        cout << "   " << smArray[i].getRow();
        cout << "   " << smArray[i].getVal();
        cout << endl;

    }
}


// functions to swap the matrix term individually
void swapMatrixTerm(MatrixTerm& a, MatrixTerm& b){
    int tempRow = a.getRow(),
        tempCol = a.getCol(),
        tempVal = a.getVal();

    a.setRow(b.getRow());
    a.setCol(b.getCol());
    a.setValue(b.getVal());
    b.setRow(tempRow);
    b.setCol(tempCol);
    b.setValue(tempVal);
}


// sort the sparseMatrix by similar approach of selection sort
void sortSparseMatrix(MatrixTerm* mt, int terms){
    int min;

    for(int i = 0; i < terms - 1; i++)
    {
        min = i;
        for(int j = i + 1; j < terms; j++)
        {
            if(mt[j].getRow() < mt[min].getRow()) {
                min = j;
            }

            else if((mt[j].getRow() == mt[min].getRow()) && (mt[j].getCol() < mt[min].getCol())) {
                min = j;
            }
        }
        swapMatrixTerm(mt[i], mt[min]);

    }

}


// resize the sparse matrix if the capcity is full
void SparseMatrix::resize(const int newSize){
    MatrixTerm* temp = new MatrixTerm[newSize];

    // move original value into the new resized MatrixTerm
    for(int i = 0; i < terms; i++)
    {
        temp[i].setRow(smArray[i].getRow());
        temp[i].setCol(smArray[i].getCol());
        temp[i].setValue(smArray[i].getVal());
    }
    
    // delete the original MatrixTerm
    delete[] smArray;
    smArray = temp;
    capacity = newSize;
}


// overloads the >> operator to input matrix term
istream& operator>>(istream& is, SparseMatrix& sm)
{
    int r, c, v;
    is >> r >> c >> v;

    // exception detector
    try {
        if(r >= sm.rows) 
            throw "Row out of bounds!!";
        else if(c >= sm.cols)
            throw "Column out of bounds!!";
    }

    catch (const char* error)
    {
        cout << error << endl;
        return is;
    }
        

    // resize if the sparse matrix is full
    if(sm.terms == sm.capacity){
        sm.resize(2 * sm.capacity);
        cout << "resized" << endl;
    }
    
    // sets the new value
    sm.smArray[sm.terms].setRow(r);
    sm.smArray[sm.terms].setCol(c);
    sm.smArray[sm.terms].setValue(v);
    sm.terms++;

    // sort the sparse array 
    sortSparseMatrix(sm.smArray, sm.terms);

    return is;
}

ostream& operator<<(ostream& os, SparseMatrix& sm) {
    int _term = 0,
        _row = 0,
        _col = 0;


    while( _row < sm.rows) {
        while(_col < sm.cols) {
            if(_term > sm.terms) {
                os << "   0";
            }

            else if(_row == sm.smArray[_term].getRow() && _col == sm.smArray[_term].getCol()) {
                os << "   " << sm.smArray[_term].getVal();
                _term++;
            }

            else {
                os << "   " << "0";
            }
            _col++;
        }
        os << endl;
        _col = 0;
        _row++;
    }
    return os;
}