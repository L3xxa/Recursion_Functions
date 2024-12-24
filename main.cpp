#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

// Ініціалізація масиву випадковими числами
void initialize(int *A, int n, int i = 0) {
    if ( i == n) {
        return;
    }
    A[i] = rand() % 201 - 50;
    cout << setw(4) << A[i] << " ";

    if (i % 10 == 9) {
        cout << endl;
    }
    initialize(A, n, i + 1);
}
// Згаходження мінімального значення суми 10 елементів масиву
int Min(int *A, int n, int i = 0, int min = 0) {
   if (i + 9 >= n) {
       return min;
   }

    int sum = 0;
    for (int j = 0; j < 10; j++) {
        sum += A[i + j];
    }

    if (i == 0) {
        min = sum;
    }

    if (sum < min) {
        min = sum;
    }

    return Min(A, n, i + 1, min);

}

int main() {
    srand(time(0));

    int *A = new int [100];
    int n = 100;

    initialize(A, n);// Ініціалізація масиву випадковими числами

    Min(A, n); // Знаходження мінімального значення суми 10 елементів масиву
    cout << "Min sum of 10 elements: " << Min(A, n) << endl;

    delete[] A;
    return 0;
}