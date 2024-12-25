#include <iostream>
using namespace std;

int NSD (int a, int b) {
    if (b == 0) {
        return a;
    }
    return NSD (b, a % b);
}

int main() {

    int a;
    int b;
    cout << "Enter a number: ";
    cin >> a;
    cout << "Enter another number: ";
    cin >> b;
    cout << "Let's find the greatest common divisor " << endl;

    cout << "NSD = " << NSD(a, b) << endl;
    return 0;
}