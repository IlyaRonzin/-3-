#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <locale>

using namespace std;

map<char, string> createMorseMap() {
    map<char, string> m;
    m['А'] = ".-";
    m['Б'] = "-...";
    m['В'] = ".--";
    m['Г'] = "--.";
    m['Д'] = "-..";
    m['Е'] = ".";
    m['Ж'] = "...-";
    m['З'] = "--..";
    m['И'] = "..";
    m['Й'] = ".---";
    m['К'] = "-.-";
    m['Л'] = ".-..";
    m['М'] = "--";
    m['Н'] = "-.";
    m['О'] = "---";
    m['П'] = ".--.";
    m['Р'] = ".-.";
    m['С'] = "...";
    m['Т'] = "-";
    m['У'] = "..-";
    m['Ф'] = "..-.";
    m['Х'] = "....";
    m['Ц'] = "-.-.";
    m['Ч'] = "---.";
    m['Ш'] = "----";
    m['Щ'] = "--.-";
    m['Ъ'] = ".--.-.";
    m['Ы'] = "-.--";
    m['Ь'] = "-..-";
    m['Э'] = "..-..";
    m['Ю'] = "..--";
    m['Я'] = ".-.-";
    return m;
}

int main() {
    setlocale(LC_ALL, "Russian");

    map<char, string> morseCode = createMorseMap();

    string input;
    cout << "Введите сообщение: ";
    getline(cin, input);

    transform(input.begin(), input.end(), input.begin(), ::toupper);

    string output;
    for (char c : input) {
        if (c == ' ') continue;
        auto it = morseCode.find(c);
        if (it != morseCode.end()) {
            output += it->second + " ";
        }
    }

    if (!output.empty() && output.back() == ' ') {
        output.pop_back();
    }

    cout << "Сообщение в азбуке Морзе: " << output << endl;

    return 0;
}