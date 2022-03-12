#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H
#include <iostream>
using namespace std;


class SparseMatrix;
//void sortSparseMatrix(MatrixTerm* mt, int terms);
//void swapMatrixTerm(MatrixTerm& a, MatrixTerm& b);


// class MatrixTerm
class MatrixTerm {
    friend SparseMatrix;

private:
    int row, col, value;

public:
    // constructor
    MatrixTerm(int r = 0, int c = 0, int v = 0)
    :row(r), col(c), value(v) {}
    
    // destructor
    virtual ~MatrixTerm(){}
    
    // getter function
    int getRow() { return row; }
    int getCol() { return col; }
    int getVal() { return value; }
   
    // setter function
    void setRow(int r) { row = r; }
    void setCol(int c) { col = c; }
    void setValue(int v) { value = v; }
    
};

// class SparseMatrix
class SparseMatrix{
private:
    int rows, cols, terms, capacity;
    MatrixTerm * smArray;

public:
    // constructor
    SparseMatrix(int r = 1, int c = 1, int cap = 1): 
    rows(r), cols(c), capacity(cap){

        terms = 0; // Sparse Matrix initialized
                   // should have 0 non-zero entries
        smArray = new MatrixTerm[cap];
    }

    // destructor
    virtual ~SparseMatrix(){}

    // operator>> overload
    friend istream& operator>>(istream&, SparseMatrix&);
    
    // operator<< overload
    friend ostream& operator<<(ostream&, SparseMatrix&);


    // transpose function with fast transpose method
    SparseMatrix Transpose(); 
    
    // Add function
    SparseMatrix Add(SparseMatrix b);

    // Multiply function
    SparseMatrix Multiply(SparseMatrix b);

    void addTerm(const int , const int , const int );
   

    // Resizing Method
    void resize(const int);
    int getTerm() { return terms;}
    void printSparseArray();
};


#endif