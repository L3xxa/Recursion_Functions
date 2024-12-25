#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

// Створення масиву
void createMatrix(int **A, int x, int y) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            A[i][j] = rand() % 100;
        }
    }
}

// Виведення масиву
void printMatrix(int **A, int x, int y) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cout << setw(4) << A[i][j];
        }
        cout << endl;
    }
}

// Пошук мінімального та максимального елементів головної діагоналі
void min_max(int **A, int x, int y, int &min, int &max) {
    max = A[0][0];
    min = A[0][0];
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (i == j) {
                if (A[i][j] > max) {
                    max = A[i][j];
                }
                if (A[i][j] < min) {
                    min = A[i][j];
                }
            }
        }
    }
}

// Сортування рядків масиву
void sort (int **A, int x, int y) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < k - 1; k++) {
                if (A[i][k] > A[i][k + 1]) {
                    int temp = A[i][k];
                    A[i][k] = A[i][k + 1];
                    A[i][k + 1] = temp;
                }
            }
        }
    }
}

int main() {
    srand(time(0));

    int x = 5, y = 5;
    int **A = new int *[x];
    for (int i = 0; i < x; i++) {
        A[i] = new int[y];
    }

    createMatrix(A, x, y); // Створеня масиву
    printMatrix(A, x, y); // Виведення масиву

    // Пошук мінімального та максимального елементів головної діагоналі
    int min, max;
    min_max(A, x, y, min, max);
    cout << "Min main diagonal = " << min << endl;
    cout << "Max main diagonal = " << max << endl;

    sort(A, x, y); // Сортування рядків масиву
    cout << "Sorted matrix:" << endl;
    printMatrix(A, x, y); // Виведення масиву

    // Звільнення пам'яті
    for (int i = 0; i < x; i++) {
        delete[] A[i];
    }
    delete[] A;
    return 0;
}