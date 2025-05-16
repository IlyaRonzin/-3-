/* Полная реализация класса MorseConverter в одном файле */

#include "MorseConverter.h"

class MorseConverter {
private:
    map<char, string> morseMap;

    void initializeMap() {
        // Русские символы
        morseMap['А'] = ".-";
        morseMap['Б'] = "-...";
        morseMap['В'] = ".--";
        morseMap['Г'] = "--.";
        morseMap['Д'] = "-..";
        morseMap['Е'] = ".";
        morseMap['Ж'] = "...-";
        morseMap['З'] = "--..";
        morseMap['И'] = "..";
        morseMap['Й'] = ".---";
        morseMap['К'] = "-.-";
        morseMap['Л'] = ".-..";
        morseMap['М'] = "--";
        morseMap['Н'] = "-.";
        morseMap['О'] = "---";
        morseMap['П'] = ".--.";
        morseMap['Р'] = ".-.";
        morseMap['С'] = "...";
        morseMap['Т'] = "-";
        morseMap['У'] = "..-";
        morseMap['Ф'] = "..-.";
        morseMap['Х'] = "....";
        morseMap['Ц'] = "-.-.";
        morseMap['Ч'] = "---.";
        morseMap['Ш'] = "----";
        morseMap['Щ'] = "--.-";
        morseMap['Ъ'] = ".--.-.";
        morseMap['Ы'] = "-.--";
        morseMap['Ь'] = "-..-";
        morseMap['Э'] = "..-..";
        morseMap['Ю'] = "..--";
        morseMap['Я'] = ".-.-";
    }

public:
    MorseConverter() {
        initializeMap();
        setlocale(LC_ALL, "Russian");
    }

    string convertToMorse(const string& text) {
        if (text.empty()) {
            cerr << "Ошибка: Входная строка не может быть пустой" << endl;
            return "";
        }

        string converted;
        string upperText = text;
        transform(upperText.begin(), upperText.end(), upperText.begin(), ::toupper);

        for (char c : upperText) {
            if (c == ' ') continue;

            auto morseIt = morseMap.find(c);
            if (morseIt == morseMap.end()) {
                cerr << "Ошибка: Обнаружен неподдерживаемый символ: " << c << endl;
                return "";
            }

            converted += morseIt->second + " ";
        }

        if (!converted.empty()) {
            converted.pop_back();
        }

        return converted;
    }
};