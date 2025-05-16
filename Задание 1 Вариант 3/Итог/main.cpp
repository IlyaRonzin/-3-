/* Преобразование русского текста в азбуку Морзе */

#include "MorseConverter.h"

int main() {
    setlocale(LC_ALL, "Russian");
    MorseConverter converter;

    try {
        cout << "Введите сообщение на русском языке: ";
        string input;
        getline(cin, input);

        string morse = converter.convertToMorse(input);
        cout << "\nСообщение в азбуке Морзе:\n" << morse << endl;
    }
    catch (const invalid_argument& e) {
        cerr << "Ошибка: " << e.what() << endl;
        return 1;
    }

    return 0;
}