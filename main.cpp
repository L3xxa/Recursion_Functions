#include <iostream>
using namespace std;

int degree (int N, int D) {
    if (D < 1) {
        return 1;
    }
    return N * degree(N, D - 1);
}

int main() {

    int N;
    cout << "Enter a digit: ";
    cin >> N;
    int D;
    cout << "Enter a degree: ";
    cin >> D;

    cout << N << "^" << D << " = " << degree(N, D) << endl;

    return 0;
}