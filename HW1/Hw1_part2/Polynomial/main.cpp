#include <iostream>
#include "Polynomial.h"
using namespace std;

int main() {
    Polynomial p1;
    Polynomial p2;

    cin >> p1;
    cout << p1 << endl;
    cin >> p1;
    cout << p1 << endl;

    cin >> p1;
    cout << p1 << endl;
    cin >> p1;
    cout << p1 << endl;
    cin >> p2;
    cin >> p2;

    cout << "\n----------------------------------------------------------\n" << endl;
    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;

    Polynomial p3 = p1.Add(p2);
    cout <<"p3 = p1 + p2: " <<  p3 << endl;

    Polynomial p4 = p1.Mult(p2);
    cout << "p4 = p1 * p2: " << p4 << endl;

    cout << "\nevaluation: of p4(x): " << endl;
    cout << "x: " ;
    float x;
    cin >> x; 
    cout << "answer: " << p4.Eval(x) << endl;
    cout << "coefficient of x^2 of p4: " << p4.Coef(2) << endl;
    cout << "coefficient of x^5 of p4: " << p4.Coef(5) << endl;
    cout << "coefficient of x^10 of p4: " << p4.Coef(10) << endl; 
    cout << "leading coeffiecnt of p4: " << p4.LeadExp() << endl;
    
    Polynomial p5;
    
    cout << "\nInitialize a zero polynomial p5, is p5 a zero polynomial ?" << endl;
    cout << !p5 << endl;
    cout << "\nIs p4 a zero polynomial ?" << endl;
    cout << !p4 << endl;
}