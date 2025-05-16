/* �������������� �������� ������ � ������ ����� */

#include "MorseConverter.h"

int main() {
    setlocale(LC_ALL, "Russian");
    MorseConverter converter;

    try {
        cout << "������� ��������� �� ������� �����: ";
        string input;
        getline(cin, input);

        string morse = converter.convertToMorse(input);
        cout << "\n��������� � ������ �����:\n" << morse << endl;
    }
    catch (const invalid_argument& e) {
        cerr << "������: " << e.what() << endl;
        return 1;
    }

    return 0;
}