#include <iostream>
using namespace std;

void print (int N) {
    if (N < 1) {
        return;
    }
    cout << "* ";
    print(N - 1);
}

int main() {
    int N;
    cout << "Enter a digit: ";
    cin >> N;

    print(N);
    cout << endl;

    return 0;
}