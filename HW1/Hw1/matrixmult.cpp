#include <iostream>
#include <iomanip>
using namespace std;
#define N 1
int addCount;
int multCount;


void show(int a[][N]) {
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < N; c++) {
            cout << "    " << a[r][c];
        }
        cout << endl;
    }
}

void add(int x[][N], int a[][N], int b[][N])
{
    for(int r  = 0; r < N; r++) {
        for(int c = 0; c < N; c++) {
            x[r][c] = a[r][c] + b[r][c];
            addCount++;
        }
    }
}

void sub(int x[][N], int a[][N], int b[][N]) {
    for(int r  = 0; r < N; r++) {
        for(int c = 0; c < N; c++) {
            x[r][c] = a[r][c] - b[r][c];
            addCount++;
        }
    }
}


void mult(int x[][N], int a[][N], int b[][N]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < N; k++) {
                x[i][j] += a[i][k] * b[k][j];
                addCount++;
                multCount++;
            }
        }
    }
}


int main()
{
    int A[N][N],
        B[N][N],
        C[N][N],
        D[N][N],
        AC[N][N] = {0},
        AD[N][N] = {0},
        BC[N][N] = {0},
        BD[N][N] = {0},
        AC_minus_BD[N][N] = {0},
        AD_plus_BC[N][N] = {0};

    cout << "matrix A(N x N):";
    for(int r = 0; r < N; r++)
        for(int c = 0; c < N; c++)
            cin >> A[r][c];
    
    cout << "matrix B(N X N):";
    for(int r = 0; r < N; r++)
        for(int c = 0; c < N; c++)
            cin >> B[r][c];


    cout << "matrix C(N X N):";
    for(int r = 0; r < N; r++)
        for(int c = 0; c < N; c++)
            cin >> C[r][c];

    cout << "matrix D(N X N):";
    for(int r = 0; r < N; r++)
        for(int c = 0; c < N; c++)
            cin >> D[r][c];

    mult(AC, A, C);
    mult(AD, A, D);
    mult(BC, B, C);
    mult(BD, B, D);
    sub(AC_minus_BD, AC, BD);
    add(AD_plus_BC, AD, BC);


    cout << endl;
    cout << "Matrix A = \n";
    show(A);
    cout << "Matrix B = \n";
    show(B);
    cout << "Matrix C = \n";
    show(C);
    cout << "Matrix D = \n";
    show(D);
    cout << "AC minus BD equals \n";
    show(AC_minus_BD);
    cout << "AD plus BC equals \n";
    show(AD_plus_BC);

    cout << "add count: " << addCount << " times\n";
    cout << "multiplication " << multCount << " times\n";

}