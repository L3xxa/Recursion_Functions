#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
using namespace std;

// Функція для знаходження биків та корів
void bulls_and_cows(string xNumber, string number, int &bulls, int &cows) {
    bulls = 0;
    cows = 0;

    bool usedX[4] = {false};
    bool usedN[4] = {false};

    // Пошук корів
    for (int i = 0; i < 4; i++) {
        if (xNumber[i] == number[i]) {
            cows++;
            bulls++;
            usedX[i] = true;
            usedN[i] = true;
        }
    }

    // Пошук биків
    for (int i = 0; i < 4; i++) {
        if (usedX[i]) continue;
        for (int j = 0; j < 4; j++) {
            if (!usedN[j] && xNumber[i] == number[j]) {
                bulls++;
                usedX[i] = true;
                usedN[j] = true;
                break;
            }
        }
    }
}

// Функція гри
void game(int xNumber, int &count) {
    int number;

    cout << "Enter a four-digit number: ";
    cin >> number;

    // Перевірка чи число є чотирьохзначним
    if (number < 1000 || number > 9999) {
        cout << "The number must be four-digit!" << endl;
        game(xNumber, count);
        return;
    }

    // Збільшуємо кількість спроб
    count++;

    // Перевірка на правильну відповідь
    if (number == xNumber) {
        cout << "Congratulations! You guessed the number!" << endl;
        cout << "Number of attempts: " << count << endl;
        return;
    }

    // Підрахунок биків і корів
    int bulls, cows;
    bulls_and_cows(to_string(xNumber), to_string(number), bulls, cows);
    cout << "Bulls: " << bulls << ", Cows: " << cows << endl;

    // Повторюємо гру
    game(xNumber, count);
}

int main() {
    // Вивід правил гри
    cout << "<----------------------------------------Bulls and Cows Game---------------------------------------->" << endl;
    cout << "Rules: ";
    cout << "The program generates a four-digit number, and the player must guess it."
            " After the user enters a number, the program reports how many digits of the number"
            " were guessed (bulls) and how many digits were guessed and stood in the right place (cows)." << endl;

    int start;
    cout << "Start the game? (1 - yes, 0 - no): ";
    cin >> start;
    if (start == 0) {
        cout << "Goodbye!" << endl;
        return 0;
    }

    // Генерація випадкового числа
    srand(time(0));
    int xNumber = rand() % 9000 + 1000;

    // cout << "(DEBUG) Secret number: " << xNumber << endl;

    int count = 0; // Лічильник спроб
    game(xNumber, count);

    return 0;
}
