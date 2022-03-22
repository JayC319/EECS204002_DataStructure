#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>
using namespace std;

class Polynomial;


class Term {
    friend Polynomial;
private:
    float coef;
    int exp;
public:
    Term(float c = 0, int e = 0):coef(c), exp(e) {}
    virtual ~Term(){}
    
    //setter function
    void setCoef(float c) {this->coef = c;}
    void setExp(int e) {this->exp = e;}
    
    //getter function
    float getCoef() {return this->coef;}
    int getExp() {return this->exp;}
};


class Polynomial{
private:
    Term *termArray;
    int capacity;
    int terms;
public:
    Polynomial() {
        termArray = new Term[1];
        termArray->coef = 0;
        termArray->exp = 0;
        capacity = 1;
        terms = 0;
    }; //construct the polynomial p(x) = 0
    
    virtual ~Polynomial(){} //destructor
    
    void NewTerm(const float, const int);
    
    Polynomial Add(Polynomial);
    
    Polynomial Mult(Polynomial);
    
    float Eval(float);

    int operator!() {
        if(termArray[0].coef == 0 && termArray[0].exp == 0)
            return 1;
        return 0;
    }

    friend ostream& operator<<(ostream&, Polynomial&);
    friend istream& operator>>(istream&, Polynomial&);
    float Coef(int e); // return the coefficient of e in *this
    int LeadExp(); // return the largest exponent is *this
};

#endif