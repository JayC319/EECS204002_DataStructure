#include <iostream>
#include "Polynomial.h"
using namespace std;

int main() {
    Polynomial p1;
    Polynomial p2;

    cout << "input 3 terms for polynomial 1 in the form of (coefficient, exponent)" << endl;
    cin >> p1;
    cout << "p1: " << p1 << endl;
    cin >> p1;
    cout << "p1: " << p1 << endl;
    cin >> p1;
    cout << "p1: " << p1 << endl;
    //cin >> p1;
    //cout << "p1: " << p1 << endl;

    cout << endl;
    cout << "input 4 terms for polynomial 2 in the form of (coefficient, exponent)" << endl;
    cin >> p2;
    cout << "p2: " << p2 << endl;
    cin >> p2;
    cout << "p2: " << p2 << endl;
    cin >> p2;
    cout << "p2: " << p2 << endl;
    cin >> p2;
    cout << "p2: " << p2 << endl;


    cout << "\n----------------------------------------------------------\n" << endl;
    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;


    cout << "demonstration of Add()" << endl;
    cout << "\n----------------------------------------------------------\n" << endl;
    Polynomial p3 = p1.Add(p2);
    cout <<"p3 = p1 + p2: " <<  p3 << endl;
    cout << "\n----------------------------------------------------------\n" << endl;

    cout << "demonstration of Mult()" << endl;
    cout << "\n----------------------------------------------------------\n" << endl;
    Polynomial p4 = p1.Mult(p2);
    cout << "p4 = p1 * p2: " << p4 << endl;
    cout << "\n----------------------------------------------------------\n" << endl;


    cout << "\nevaluation: of p4(x) by Eval: " << endl;
    cout << "\n----------------------------------------------------------\n" << endl;
    cout << "x: " ;
    float x;
    cin >> x; 
    cout << "answer: " << p4.Eval(x) << endl;
    cout << "\n----------------------------------------------------------\n" << endl;

    cout << "determine the Coef function of p4 by check Coef(2), Coef(5), Coef(10)" << endl;
    cout << "\n----------------------------------------------------------\n" << endl;
    cout << "coefficient of x^2 of p4: " << p4.Coef(2) << endl;
    cout << "coefficient of x^5 of p4: " << p4.Coef(5) << endl;
    cout << "coefficient of x^10 of p4: " << p4.Coef(10) << endl;
    cout << "\n----------------------------------------------------------\n" << endl;

    cout << "determine the leading exponent of p4 and p2" << endl;
    cout << "\n----------------------------------------------------------\n" << endl;
    cout << "leading coefficient of p4: " << p4.LeadExp() << endl;
    cout << "leading coefficient of p2: " << p2.LeadExp() << endl;
    cout << "\n----------------------------------------------------------\n" << endl;


    cout << "demonstrate the operator! by checking whether a polynomial is zero polynomial" << endl;    
    cout << "\n----------------------------------------------------------\n" << endl;
    Polynomial p5;
    cout << "\nInitialize a zero polynomial p5, is p5 a zero polynomial ?" << endl;
    cout << !p5 << endl;
    cout << "\nIs p4 a zero polynomial ?" << endl;
    cout << !p4 << endl;
    cout << "\n----------------------------------------------------------\n" << endl;

}