#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <queue>
#include <list>
#include <iomanip>
using namespace std;

typedef struct {
    int row;
    int col;
    int value;
} Triple;

class MatrixNode;
class Matrix;


class MatrixNode {
    friend class Matrix;
    friend istream& operator>>(istream&, Matrix&);
    friend ostream& operator<<(ostream&, Matrix&);
private:
    MatrixNode* down, *right;
    bool head;
    union {
        MatrixNode* next;
        Triple triple;
    };
    MatrixNode(bool, Triple*);
};


class Matrix {
    friend istream& operator>>(istream&, Matrix&);
    friend ostream& operator<<(ostream&, Matrix&);
public:
    static MatrixNode * availableNodePool;
    Matrix();
    Matrix(const Matrix&);
    ~Matrix();
    Matrix transpose() const;
    Matrix& operator=(const Matrix&);
    Matrix operator+(const Matrix&) const;
    Matrix operator*(const Matrix&) const;
    void setNode(list<Triple>&);
    void getNode(list<Triple>&) const;
private:
    MatrixNode* headNode;
};





#endif