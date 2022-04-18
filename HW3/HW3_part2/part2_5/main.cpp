#include "Matrix.h"
#include <time.h>

int main() {
    Matrix M1;
    Matrix M2;
    Matrix M3;

    cout << "input for M1:" << endl;
    cin >> M1;
    cout << "\ninput for M2:" << endl;
    cin >> M2;
    cout << "\ninput for M3:" << endl;
    cin >> M3;

    
    cout << "M1:\n" << M1 << endl;
    cout << "M2:\n" << M2 << endl;
    cout << "M3:\n" << M3 << endl;

    Matrix SumMatrix(M1+M3);
    Matrix MultMatrix(M1*M2);
    cout << "SumMatrix = M1 + M3:\n" << SumMatrix << endl;
    cout << "Multmatrix = M1 * M2:\n" << MultMatrix << endl;

    cout << "[test for time of copy constructor of multiplication of Summatrix and Multmatrix]" << endl;
    clock_t start, stop;
    double duration = 0;
    int counter = 0;
    do {
        counter++;
        start = clock();
        Matrix CopyMatrix(SumMatrix*MultMatrix);
        stop = clock();
        duration += stop - start;
    }while (duration < 10);
    cout << "\nthe testing time result is: " << duration / counter / double(CLOCKS_PER_SEC) << "s" << endl << endl;

    cout << "[test for transpose of the MultMatrix]" << endl;
    cout << "before transpose:\n" << MultMatrix << endl;
    Matrix TransposeM(MultMatrix.transpose());
    cout << "after transpose:\n" << TransposeM << endl;


    cout << "end" << endl;
}