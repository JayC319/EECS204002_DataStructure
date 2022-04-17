#include "Polynomial.h"
#include <iostream>

using namespace std;



int main() {

    cout << "*****Start testbench:*****" << endl;
    
    cout << "\n[Initializing polynomial P1 and P2 using overloading >> ]" << endl;
    Polynomial P1;
    cout << "P1:" << endl;
    cin >> P1;

    Polynomial P2;
    cout << "P2:" << endl;
    cin >> P2;

    cout << "\n[test for copy constructor]: " << endl;
    cout << "P1: " << P1 << endl;
    Polynomial copyPoly(P1);
    cout << "copyPolynomial: " << copyPoly << endl;

    cout << "\n[test for assignment operator =]: " << endl;
    cout << "copyPolynomial: " << copyPoly << endl;
    cout << "P2: " << P2 << endl;
    cout << "~~~~~~copyPolynomial = P2~~~~~~" << endl;
    copyPoly = P2;
    cout << "copyPolynomial: " << copyPoly << endl;
    

    cout << "\n[test for operator +]: " << endl;
    Polynomial sumPoly;
    cout << "sumPoly: " << sumPoly << endl;
    cout << "P1: " << P1 << endl;
    cout << "P2: " << P2 << endl;
    cout << "sumPoly = P1 + P2 " << endl;
    sumPoly = P1 + P2;
    cout << "sumPoly: " << sumPoly << endl;


    cout << "\n[test for operator -]: " << endl;
    Polynomial resPoly;
    cout << "resPoly: " << resPoly << endl;
    cout << "P1: " << P1 << endl;
    cout << "P2: " << P2 << endl;
    cout << "resPoly = P1 - P2 " << endl;
    resPoly = P1 - P2;
    cout << "resPoly: " << resPoly << endl;

    
    cout << "\n[test for operator *]: " << endl;
    Polynomial multPoly;
    cout << "multPoly: " << multPoly << endl;
    cout << "P1: " << P1 << endl;
    cout << "P2: " << P2 << endl;
    cout << "multPoly = P1 + P2 " << endl;
    multPoly = P1 * P2;
    cout << "multPoly: " << multPoly << endl;

    cout << "\n[test for evaluate]: " << endl;
    cout << "\ninput a number for evaluation for multPoly m(x), x: ";
    double x;
    cin >> x;
    cout << "m(" << x << ") =  " << multPoly.evaluate(x) << endl;

    cout << "\n***** end testbench *****" << endl;
        
}