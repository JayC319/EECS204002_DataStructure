#include "Polynomial.h"
#include <iostream>
#include <math.h>
using namespace std;


void swapPolynomialTerm(Term& a, Term& b) {
    int tempCoef = a.getCoef(),
        tempExp = a.getExp();

    a.setCoef(b.getCoef());
    a.setExp(b.getExp());
    
    b.setCoef(tempCoef);
    b.setExp(tempExp);
}


void sortDescendingExponent(Term* t, int terms) {
    int max;
    for(int i = 0; i < terms - 1; i++) {
        max = i;
        for(int j = i+1; j < terms; j++) {
            if(t[j].getExp() > t[max].getExp())
                max = j;
        }
        swapPolynomialTerm(t[i], t[max]);
    }
}

//*****************************
//
//*****************************
void Polynomial::NewTerm(const float c, const int e) {
    if(terms == capacity)
    {
        capacity *= 2;
        Term *temp = new Term[capacity];
        for(int i = 0; i < terms; i++) {
            temp[i].coef = termArray[i].coef;
            temp[i].exp = termArray[i].exp;
        }
        delete[] termArray;
        termArray = temp;
    }

    termArray[terms].coef = c;
    termArray[terms].exp = e;
    terms++;
}

//*****************************
//
//*****************************
Polynomial Polynomial::Add(Polynomial b){
    Polynomial c;
    int aPos = 0, bPos = 0;
    while((aPos < terms) && (bPos < b.terms)) {
        if(termArray[aPos].exp == b.termArray[bPos].exp) {
            float t = termArray[aPos].coef + b.termArray[bPos].coef;
            if(t) c.NewTerm(t, termArray[aPos].exp);
            aPos++;
            bPos++;
        }

        else if(termArray[aPos].exp < b.termArray[bPos].exp) {
            c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
            bPos++;
        }

        else {
            c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
            aPos++;
        }
    }

    for(; aPos < terms; aPos++)
        c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);

    for( ; bPos < b.terms; bPos++)
        c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
    
    return c;
}

//*****************************
//
//*****************************

Polynomial Polynomial::Mult(Polynomial b) {
    int array[termArray[0].getExp() + b.termArray[0].getExp()] = {0};

    for(int pos1 = 0; pos1 < terms; pos1++)
        for(int pos2 = 0; pos2 < b.terms; pos2++)
            array[termArray[pos1].getExp() + b.termArray[pos2].getExp() - 1] += (termArray[pos1].getCoef() * b.termArray[pos2].getCoef());
    Polynomial c;

    for(int index = (termArray[0].exp + b.termArray[0].exp -1); index >=0; index--) {
        if(array[index] != 0)
            c.NewTerm(array[index], index+1);
    }
    return c;
}


//*****************************
//
//*****************************
ostream &operator<<(ostream &os, Polynomial &p) {
    
    if(p.termArray[0].getCoef() > 0) {
        os << p.termArray[0].getCoef() << "X^" << p.termArray[0].getExp();
    }

    else if(p.termArray[0].getCoef() < 0) {
        os << "(" << p.termArray[0].getCoef() << ")"
        << "X^" << p.termArray[0].getExp();
    }

    else {
        os << "0";
        return os;
    }

    for(int i = 1; i < p.terms; i++){
        if(p.termArray[i].getCoef() > 0) {
            if(p.termArray[i].getExp() == 0) {
                os << " + " << p.termArray[i].getCoef();
            }
            
            else {
                os << " + " << p.termArray[i].getCoef()
                   << "X^" << p.termArray[i].getExp(); 
            }
        }

        else {
            if(p.termArray[i].getExp() == 0) {
                os << " + " << "(" << p.termArray[i].getCoef() << ")";
            }

            else {
                os << " + "
                   << "(" << p.termArray[i].getCoef() << ")"
                   << "X^" << p.termArray[i].getExp();
            }
        }
    }
    return os;
}



istream &operator>>(istream &is, Polynomial &p) {
    float c;
    int e;
    is >> c >> e;


    for(int i = 0; i < p.terms; i++ ){
       if(p.termArray[i].getExp() == e) {
           p.termArray[i].setCoef(p.termArray[i].getCoef() + c);
           return is;
       } 
    }
    p.NewTerm(c, e);
    sortDescendingExponent(p.termArray, p.terms);
    return is;
}  

//*****************************
//
//*****************************
float Polynomial::Eval(float f) {
    float evaluation;
    for(int i = 0; i < terms; i++) {
        evaluation += termArray[i].coef*pow(f, termArray[i].exp);
    }

    return evaluation;
}

//*****************************
//
//*****************************
float Polynomial::Coef(int e) {
    if(termArray[0].getExp() < e)
        return -1;
    
    if(e == termArray[0].getExp())
        return termArray[0].getCoef();
    
    int index = 1;

    while(termArray[index].getExp() >= e && index < terms) {
        if(termArray[index].getExp() == e)
            return termArray[index].getCoef();
        else
            index++;
    }
    return -1;
}

//*****************************
//
//*****************************
int Polynomial::LeadExp() {
    return termArray[0].getExp();
}