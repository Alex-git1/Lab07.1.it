#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** Z, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** Z, const int rowCount, const int colCount);
void SortColumns(int** Z, const int rowCount, const int colCount);
void SwapColumns(int** Z, const int col1, const int col2, const int rowCount);
void Calc(int** Z, const int rowCount, const int colCount, int& S, int& k);

int main() {
    srand((unsigned)time(NULL));
    int Low = 4;
    int High = 45;
    int rowCount = 9;
    int colCount = 7;

    int** Z = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        Z[i] = new int[colCount];

    Create(Z, rowCount, colCount, Low, High);
    Print(Z, rowCount, colCount);
    SortColumns(Z, rowCount, colCount);
    Print(Z, rowCount, colCount);

    int S = 0;
    int k = 0;
    Calc(Z, rowCount, colCount, S, k);
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;
    Print(Z, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] Z[i];
    delete[] Z;

    return 0;
}

void Create(int** Z, const int rowCount, const int colCount, const int Low, const int High) {
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            Z[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** Z, const int rowCount, const int colCount) {
    cout << endl;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << Z[i][j];
        cout << endl;
    }
    cout << endl;
}

void SortColumns(int** Z, const int rowCount, const int colCount) {
    for (int i = 0; i < colCount - 1; i++) {
        for (int j = 0; j < colCount - i - 1; j++) {
            if (Z[0][j] < Z[0][j + 1]) {
                SwapColumns(Z, j, j + 1, rowCount);
            }
        }
    }

    for (int i = 0; i < colCount - 1; i++) {
        for (int j = 0; j < colCount - i - 1; j++) {
            if (Z[0][j] == Z[0][j + 1] && Z[1][j] > Z[1][j + 1]) {
                SwapColumns(Z, j, j + 1, rowCount);
            }
        }
    }

    for (int i = 0; i < colCount - 1; i++) {
        for (int j = 0; j < colCount - i - 1; j++) {
            if (Z[0][j] == Z[0][j + 1] && Z[1][j] == Z[1][j + 1] && Z[2][j] < Z[2][j + 1]) {
                SwapColumns(Z, j, j + 1, rowCount);
            }
        }
    }
}

void SwapColumns(int** Z, const int col1, const int col2, const int rowCount) {
    for (int i = 0; i < rowCount; i++) {
        int tmp = Z[i][col1];
        Z[i][col1] = Z[i][col2];
        Z[i][col2] = tmp;
    }
}

void Calc(int** Z, const int rowCount, const int colCount, int& S, int& k) {
    S = 0;
    k = 0;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            if (Z[i][j] % 2 == 0 && !(i % 2 != 0 || j % 2 != 0)) {
                S += Z[i][j];
                k++;
                Z[i][j] = 0; 
            }
        }
    }
}
