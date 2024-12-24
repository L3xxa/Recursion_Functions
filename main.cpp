#include <iostream>
using namespace std;

int Sum(int A, int B) {
    if (A == B) {
        cout << A;
        return A;
    }
    cout << A << " + ";

    return A + Sum(A + 1, B);
}

int main() {
    int A;
    cout << "Enter a first digit: ";
    cin >> A;

    int B;
    cout << "Enter a second digit: ";
    cin >> B;

    if (A >= B) {
        cout << "Invalid! A must be less than B." << endl;
        return 1;
    }

    cout << "Sum: ";
    int result = Sum(A, B);
    cout << " = " << result << endl;

    return 0;
}
