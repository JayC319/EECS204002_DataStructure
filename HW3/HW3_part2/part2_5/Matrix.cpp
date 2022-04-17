#include "Matrix.h"
#include "queue"
#include "list"


MatrixNode::MatrixNode(bool b, Triple *t) {
    head = b;
    if(b) {
        right = this;
        down = this;
        next = this;
    }
    else {
        triple = *t;
    }
}

/**************************************************************/
MatrixNode* Matrix::availableNodePool;


Matrix::Matrix() {
    // setup Pool of available Node; 
    availableNodePool = new MatrixNode(true, NULL);
    availableNodePool->right = availableNodePool;
}


Matrix::Matrix(const Matrix& b) {
    availableNodePool = new MatrixNode(true, 0);
    availableNodePool->right = availableNodePool;

    list<Triple> listofTriple;
    b.getNode(listofTriple);
    setNode(listofTriple);
}


Matrix::~Matrix() {
    if(!headNode)
        return;
    
    MatrixNode* x = headNode->right;
    headNode->right = availableNodePool;
    availableNodePool = headNode;
    while(x != headNode) {
        MatrixNode* y = x->right;
        availableNodePool = y;
        x = x->next;
    }
    headNode = NULL;
}


void Matrix::setNode(list<Triple>& listofTriple) {    
    Triple s = listofTriple.front();
    listofTriple.pop_front();

    headNode = new MatrixNode(false, &s);
    int p = max(s.col, s.row);

    if(p == 0) {
        headNode->right = headNode;
        return;
    }

    MatrixNode **head = new MatrixNode* [p];
    for(int i = 0; i < p; i++) 
        head[i] = new MatrixNode(true, 0);
    
    int currentRow = 0;
    MatrixNode *last = head[0];

    for (int i = 1; i <= s.value; i++) {
        Triple t = listofTriple.front();
        listofTriple.pop_front();
        if(t.row > currentRow) {
            last->right = head[currentRow];
            currentRow = t.row;
            last = head[currentRow];
        }
        last = last->right = new MatrixNode(false, &t);
        head[t.col]->next = head[t.col]->next->down = last;
    }

    last->right = head[currentRow];
    for(int i = 0; i < s.col; i++)
        head[i]->next->down = head[i];

    for(int i = 0; i < p - 1; i++) 
        head[i]->next = head[i + 1];

    head[p - 1]->next = headNode;
    headNode->right = head[0];

    delete[] head;
}


void Matrix::getNode(list<Triple>& listofTriple) const{
    MatrixNode* currRow = headNode->right;
    MatrixNode* term = currRow->right;
    

    Triple tempTriple;
    tempTriple = headNode->triple;
    listofTriple.push_back(tempTriple);

    
    while(currRow != headNode) {
        while (term != currRow) {
            tempTriple = term->triple;
            listofTriple.push_back(tempTriple);
            term = term->right;
        }
        currRow = currRow->next;
        term = currRow->right;
    }
}


istream& operator>>(istream& is, Matrix& matrix) {
    list<Triple>   listofTriple;
    Triple tempTriple;
    is >> tempTriple.row >> tempTriple.col >> tempTriple.value;
    listofTriple.push_back(tempTriple);
    for (int i = 1; i <= listofTriple.front().value; i++) {
        is >> tempTriple.row >> tempTriple.col >> tempTriple.value;
        listofTriple.push_back(tempTriple);
    }

    matrix.setNode(listofTriple);
    return is;
}


ostream& operator<<(ostream& os, Matrix& matrix) {
    list<Triple> listofTriple;
    int count = 1;

    matrix.getNode(listofTriple);

    int matCol, matRow, matTerm;
    matTerm = listofTriple.front().value;
    matRow = listofTriple.front().row;
    matCol = listofTriple.front().col;
    listofTriple.pop_front();

    for(int r = 0; r < matRow; r++) {
        for(int c = 0; c < matCol; c++) {
            if(r == listofTriple.front().row && c == listofTriple.front().col) {
                os << setw(3) << listofTriple.front().value;
                listofTriple.pop_front();
            }
            else 
                os << setw(3) << "0";
        }
        os << endl;
    }
    return os;
}


Matrix& Matrix::operator=(const Matrix& b) {
    list<Triple> listofTriple;
    b.getNode(listofTriple);
    setNode(listofTriple);
    return *this;
}


Matrix Matrix::operator+(const Matrix& b) const {
    Matrix sumMatrix;
    list<Triple> listTripleA;
    list<Triple> listTripleB;
    list<Triple> listTripleC;

    getNode(listTripleA);
    b.getNode(listTripleB);

    if(listTripleA.front().col != listTripleB.front().col || listTripleA.front().row != listTripleA.front().row)
        cerr << "Cannot sum the matrix due to dimensions not match";

    int numA, numB;
    int termCount = 0;
    int rowA, colA;
    Triple tempTriple;


    numA = listTripleA.front().value;
    rowA = listTripleA.front().row;
    colA = listTripleA.front().col;
    numB = listTripleB.front().value;
    listTripleA.pop_front();
    listTripleB.pop_front();

    while(!listTripleA.empty() && !listTripleB.empty()) {
        if(listTripleA.front().row == listTripleB.front().row && listTripleA.front().col == listTripleB.front().col) {
            tempTriple.row = listTripleA.front().row;
            tempTriple.col = listTripleA.front().col;
            tempTriple.value = listTripleA.front().value + listTripleB.front().value;
            listTripleC.push_back(tempTriple);
            listTripleA.pop_front();
            listTripleB.pop_front();
            termCount++;
        }

        else if (listTripleA.front().row == listTripleB.front().row && listTripleA.front().col < listTripleB.front().col) {
            tempTriple.row = listTripleA.front().row;
            tempTriple.col = listTripleA.front().col;
            tempTriple.value = listTripleA.front().value;
            listTripleC.push_back(tempTriple);
            listTripleA.pop_front();
            termCount++;
        }

        else if (listTripleA.front().row == listTripleB.front().row && listTripleA.front().col > listTripleB.front().col) {
            tempTriple.row = listTripleB.front().row;
            tempTriple.col = listTripleB.front().col;
            tempTriple.value = listTripleB.front().value;
            listTripleC.push_back(tempTriple);
            listTripleB.pop_front();
            termCount++;
        }

        else if (listTripleA.front().row < listTripleB.front().row) {
            tempTriple.row = listTripleA.front().row;
            tempTriple.col = listTripleA.front().col;
            tempTriple.value = listTripleA.front().value;
            listTripleC.push_back(tempTriple);
            listTripleA.pop_front();
            termCount++;
        }

        else if (listTripleA.front().row > listTripleB.front().row) {
            tempTriple.row = listTripleB.front().row;
            tempTriple.col = listTripleB.front().col;
            tempTriple.value = listTripleB.front().value;
            listTripleC.push_back(tempTriple);
            listTripleB.pop_front();
            termCount++;
        } 
    }

    while(!listTripleA.empty()) {
            tempTriple.row = listTripleA.front().row;
            tempTriple.col = listTripleA.front().col;
            tempTriple.value = listTripleA.front().value;
            listTripleC.push_back(tempTriple);
            listTripleA.pop_front();
            termCount++;
        }

    while(!listTripleB.empty()) {
        tempTriple.row = listTripleB.front().row;
        tempTriple.col = listTripleB.front().col;
        tempTriple.value = listTripleB.front().value;
        listTripleC.push_back(tempTriple);
        listTripleB.pop_front();
        termCount++;
    }

    tempTriple.row = rowA;
    tempTriple.col = colA;
    tempTriple.value = termCount;
    listTripleC.push_front(tempTriple);
    sumMatrix.setNode(listTripleC);

    return sumMatrix;
}


Matrix Matrix::transpose() const {
    Matrix transposeMatrix;
    MatrixNode* currRow = headNode->right;
    MatrixNode* term = currRow->down;

    list<Triple> listofTriple;
    Triple tempTriple;

    tempTriple.row = headNode->triple.col;
    tempTriple.col = headNode->triple.row;
    tempTriple.value = headNode->triple.value;
    listofTriple.push_back(tempTriple);

    while(currRow != headNode) {
        while(term != currRow) {
            tempTriple.row = term->triple.col;
            tempTriple.col = term->triple.row;
            tempTriple.value = term->triple.value;
            listofTriple.push_back(tempTriple);
            term = term->down;
        }
        currRow = currRow->next;
        term = currRow->down;
    }

    transposeMatrix.setNode(listofTriple);
    return transposeMatrix;
}


Matrix Matrix::operator*(const Matrix& b) const {
    Matrix multMatrix;
    Matrix transposeB(b.transpose());
    
    if(headNode->triple.col != b.headNode->triple.row)
        throw "dimension not matched";

    MatrixNode* curRow = headNode->right;
    MatrixNode* term = curRow->right;
    MatrixNode* curRowB = transposeB.headNode->right;
    MatrixNode* termB = curRowB->right;


    list<Triple> listofTriple;
    int curProduct = 0;
    int termNum = 0;
    Triple tempTriple;

    while (curRow != headNode) {
        curRowB = transposeB.headNode->right;
        termB = curRowB->right;
        while (curRowB != transposeB.headNode) {
            while(termB != curRowB && term != curRow) {
                if(term->triple.col == termB->triple.col) {
                    curProduct += (term->triple.value * termB->triple.value);
                    term = term->right;
                    termB = termB->right;
                }

                else if(term->triple.col < termB->triple.col) {
                    term = term->right;
                }

                else if (term->triple.col > termB->triple.col) {
                    termB = termB->right;
                }
                
            }
            
            tempTriple.row = curRow->right->triple.row;
            tempTriple.col = curRowB->right->triple.row;
            tempTriple.value = curProduct;

            if(curProduct) {
                listofTriple.push_back(tempTriple);
                termNum++;
            }
            curProduct = 0;
            curRowB = curRowB->next;
            termB = curRowB->right;
            term = curRow->right;
        }
        curRow = curRow->next;
        term = curRow->right;
    }


    tempTriple.row = headNode->triple.row;
    tempTriple.col = b.headNode->triple.col;
    tempTriple.value = termNum;
    listofTriple.push_front(tempTriple);
    multMatrix.setNode(listofTriple);
    return multMatrix;
}