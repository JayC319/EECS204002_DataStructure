#include "sparseMatrix.h"
#include <iostream>
#include <stdexcept>
#include <limits>

//************************************************************************
// function to check if matrix addition is valid, else throw exceptions  *
//************************************************************************
void exceptionCheck1 (const int r1, const int r2, const int c1, const int c2) {
    cout << "checking" << endl;
    if((r1!=r2) || (c1 != c2)){
        cout << "throwing" << endl;
        throw "Error columns or rows not match.";
    }
            
}

//******************************************************************************
// function to check if matrix multiplication is valid, else throw exceptions  *
//******************************************************************************
void exceptionCheck2 (const int c, const int r) {
    cout << "checking" << endl;
    if(c != r) {
        cout << "throwing" << endl;
        throw "First matrix's column number and second matrix's row number is not matched!";
    }
        
}


//*******************************************************************
// function to print the matrix in order of row -> column -> value *
//*******************************************************************
void SparseMatrix::printSparseArray() {
    for (int i = 0; i < terms; i++ ){
        cout << "   " << smArray[i].getRow();
        cout << "   " << smArray[i].getCol();
        cout << "   " << smArray[i].getVal();
        cout << endl << endl;
    }
}

//*************************************************
// function to swap the matrix term individually *
//*************************************************
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

//**************************************************************
// sort the sparseMatrix by similar approach of selection sort *
//**************************************************************
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

//*************************************************
// resize the sparse matrix if the capcity is full*
//*************************************************
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

//*************************************************
// overloads the >> operator to input matrix term *
//*************************************************
istream& operator>>(istream& is, SparseMatrix& sm)
{
    int r, c, v;
    is >> r >> c >> v;

    r-=1;
    c-=1;
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

    for(int i = 0; i < sm.getTerm(); i++) {
        if(sm.smArray[i].getCol() == c && sm.smArray[i].getRow() == r) {
            sm.smArray[i].setValue(v);
            sortSparseMatrix(sm.smArray, sm.terms);
            return is;
        }
    }

    // resize if the sparse matrix is full
    if(sm.terms == sm.capacity){
        sm.resize(2 * sm.capacity);
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


//*************************
// operator<< overloading *
//*************************
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

//****************************
// method to assign new term *
//****************************
void SparseMatrix::addTerm(const int row, const int col, const int val) {
    if(val != 0) {
        if(terms == capacity)
            resize(2 * capacity);
        smArray[terms].setRow(row);
        smArray[terms].setCol(col);
        smArray[terms].setValue(val);
        terms++;
    }
}

//*****************************************************
// method to transpose an matrix using fast transpose *
//*****************************************************
SparseMatrix SparseMatrix::Transpose()
{
    SparseMatrix b(cols, rows, terms);

    if(terms) {
        int *rowSize = new int[cols];
        int *rowStart = new int[cols];

        for(int i = 0; i < cols; i++) rowSize[i] = 0;
        for(int i = 0; i < terms; i++)
            rowSize[smArray[i].col]++;

        rowStart[0] = 0;
        for(int i = 1; i < cols; i++)
            rowStart[i] = rowStart[i-1] + rowSize[i-1];
        
        for(int i = 0; i < terms; i++) {
            int j = rowStart[smArray[i].col];
            b.smArray[j].row = smArray[i].col;
            b.smArray[j].col = smArray[i].row;
            b.smArray[j].value = smArray[i].value;
            b.terms++;
            rowStart[smArray[i].col]++;
        }
        delete [] rowSize;
        delete [] rowStart;
    }
    return b; 
}

//*******************************************************************
// functions to add two matrix and a new SparseMatrix return object *
//*******************************************************************
SparseMatrix SparseMatrix::Add(SparseMatrix b)
{   
    try {
        // if(rows != b.rows || cols != b.cols)
        //     throw "Error columns or rows not match!";
        cout << "trying" << endl;
        exceptionCheck1(rows, b.rows, cols, b.cols);
    }

    catch ( char const* e) {
        cout << "catched" << endl;
        cout << e << endl;
        SparseMatrix empty(1,1,0);
        return empty;
    }
    
    SparseMatrix temp(rows, cols, terms+b.terms);

    int pos1 = 0,
        pos2 = 0;

    while(pos1 < terms && pos2 < b.terms) {
        
        // case if now are traversing the same row
        if(smArray[pos1].getRow() == b.smArray[pos2].getRow())
        {
            // case that are traversing the same row and column
            if(smArray[pos1].getCol() == b.smArray[pos2].getCol()) {
                
                // case that the value summation is not zero
                if(smArray[pos1].getVal() + b.smArray[pos2].getVal()){
                    temp.addTerm(smArray[pos1].getRow(), smArray[pos1].getCol(), smArray[pos1].getVal() + smArray[pos2].getVal());
                    pos1++;
                    pos2++;
                }

                // case that the value summation is zero
                else {
                    pos1++;
                    pos2++;
                }
            }
            
            // case that are traversing the same row but not the same column
            // column of a < b
            else if(smArray[pos1].getCol() < b.smArray[pos2].getCol()) {
                temp.addTerm(smArray[pos1].getRow(), smArray[pos1].getCol(), smArray[pos1].getVal());
                pos1++;    
            }

            // case that are traversing the same row but not the same column
            // column of b < a
            else {
                temp.addTerm(b.smArray[pos2].getRow(), b.smArray[pos2].getCol(), b.smArray[pos2].getVal());
                pos2++;
            }
        }

        // case where the row isn't matched
        // row a < row b
        else if(smArray[pos1].getRow() < b.smArray[pos2].getRow()) {
            temp.addTerm(smArray[pos1].getRow(), smArray[pos1].getCol(), smArray[pos1].getVal());
            pos1++;
        }

        // case where the row isn't matched
        // row b < row a
        else {
            temp.addTerm(b.smArray[pos2].getRow(), b.smArray[pos2].getCol(), b.smArray[pos2].getVal());
            pos2++;
        }
    }

    while(pos1 < terms) {
        temp.addTerm(smArray[pos1].getRow(), smArray[pos1].getCol(), smArray[pos1].getVal());
        pos1++;
    }

    while(pos2 < terms) {
        temp.addTerm(b.smArray[pos2].getRow(), b.smArray[pos2].getCol(), b.smArray[pos2].getVal());
        pos2++;
    }

    return temp;
}

//****************************
// method to multiply matrix *
//****************************

SparseMatrix SparseMatrix::Multiply(SparseMatrix b) {
    try {
        // if(cols != b.rows)
        //     throw invalid_argument("First matrix's column number and second matrix's row number is not matched!");
        exceptionCheck2(cols, b.rows);
    }

    catch (const char* e) {
        cout << "catching" << endl;
        cout << e << endl;
        SparseMatrix empty(1,1,0);
        return empty;
    }


    SparseMatrix bXpose = b.Transpose();
    SparseMatrix d(rows, b.cols, 0);
    int currRowIndex = 0,
        currRowBegin = 0,
        currRowA = smArray[0].row;

    if(terms == capacity)
        resize(terms+1);
    
    bXpose.resize(bXpose.terms + 1);
    smArray[terms].row = rows;
    bXpose.smArray[b.terms].row = b.cols;
    bXpose.smArray[b.terms].col = -1;

    int sum = 0;

    while(currRowIndex < terms) {
        int currColB = bXpose.smArray[0].row;
        int currColIndex = 0;
        
        while(currColIndex <= b.terms) {
            
            if(smArray[currRowIndex].row != currRowA) {
                d.addTerm(currRowA, currColB, sum);
                sum = 0;
                currRowIndex = currRowBegin;

                while(bXpose.smArray[currColIndex].row == currColB)
                    currColIndex++;
                
                currColB = bXpose.smArray[currColIndex].row;
            }

            else if (bXpose.smArray[currColIndex].row != currColB) {
                d.addTerm(currRowA, currColB, sum);
                sum = 0;
                currRowIndex = currRowBegin;
                currColB = bXpose.smArray[currColIndex].row;
            }

            else {
                if(smArray[currRowIndex].col < bXpose.smArray[currColIndex].col)
                    currRowIndex++;
                else if (smArray[currRowIndex].col == bXpose.smArray[currColIndex].col) {
                    sum += smArray[currRowIndex].value * bXpose.smArray[currColIndex].value;
                    currRowIndex++;
                    currColIndex++;
                }

                else
                    currColIndex++;
            }
        }
        while (smArray[currRowIndex].row == currRowA)
            currRowIndex++;
        currRowBegin = currRowIndex;
        currRowA = smArray[currRowIndex].row;
    }
    return d;
}
