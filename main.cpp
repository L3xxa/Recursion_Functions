#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

// Виведення одновимірного масиву
void print_array(int *A, int n) {
    cout << "1-D Array: " << endl;
    for (int i = 0; i < n; i++) {
        A[i] = rand() % 20;
        cout << A[i] << " ";
    }
    cout << endl;
    cout << endl;
}

// Виведення двовимірного масиву
void print_array(int **B, int x, int y) {
    cout << "2-D Array: " << endl;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            B[i][j] = rand() % 50;
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Виведення тривимірного масиву
void print_array(int ***C, int x, int y, int z) {
    cout << "3-D Array: " << endl;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                C[i][j][k] = rand() % 100;
                cout << C[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << endl;
}

// Пошук максимального елемента одновимірного масиву
void Max_digit(int *A, int n) {
    int max = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }
    cout << "Max digit 1-D array: " << max << endl;
}

// Пошук максимального елемента двовимірного масиву
void Max_digit(int **B, int x, int y) {
    int max = B[0][0];
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (B[i][j] > max) {
                max = B[i][j];
            }
        }
    }
    cout << "Max digit 2-D array: " << max << endl;
}

// Пошук максимального елемента тривимірного масиву
void Max_digit (int ***C, int x, int y, int z) {
    int max = C[0][0][0];
    for (int i = 0; i < x; i++  ) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                if (C[i][j][k] > max) {
                    max = C[i][j][k];
                }
            }
        }
    }
    cout << "Max digit 3-D array: " << max << endl;
}

// Пошук максимального значення двох цілих чисел
int which_one (int num1, int num2) {
    if (num1 > num2) {
        return num1;
    } else {
        return num2;
    }
}

// Пошук максимального значення трьох цілих чисел
int which_one(int num1, int num2, int num3) {
    return which_one(which_one(num1, num2), num3);
}

int main () {
    srand(time(0));

    int x = 4, y = 4, z = 4;

    int *A = new int[x]; // 1D масив

    int **B = new int*[x]; // 2D масив
    for (int i = 0; i < x; i++) {
        B[i] = new int[y];
    }

    int ***C = new int**[x]; // 3D масив
    for (int i = 0; i < x; i++) {
        C[i] = new int*[y];
        for (int j = 0; j < y; j++) {
            C[i][j] = new int[z];
        }
    }

    print_array(A, x); // Виведення одновимірного масиву
    print_array(B, x, y); // Виведення двовимірного масиву
    print_array(C, x, y, z); // Виведення тривимірного масиву

    Max_digit(A, x); // Пошук максимального елемента одновимірного масиву
    Max_digit(B, x, y); // Пошук максимального елемента двовимірного масиву
    Max_digit(C, x, y, z); // Пошук максимального елемента тривимірного масиву

    int num1 = 10;
    int num2 = 20;
    int num3 = 30;
    cout << "Max digit between " << num1 << " and " << num2 << ": " << which_one(num1, num2) << endl;
    cout << "Max digit among " << num1 << ", " << num2 << " and " << num3 << ": " << which_one(num1, num2, num3) << endl;

    delete[] A; // Видалення одновимірного масиву

    for (int i = 0; i < x; i++) {
        delete[] B[i];
    }
    delete[] B; // Видалення двовимірного масиву

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            delete[] C[i][j];
        }
        delete[] C[i];
    }
    delete[] C; // Видалення тривимірного масиву

    return 0;
}