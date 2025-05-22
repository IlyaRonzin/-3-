/* ������ ���������� ������ MorseConverter � ����� ����� */

#include "MorseConverter.h"

class MorseConverter {
private:
    map<char, string> morseMap;

    void InitializeMap() {
        // ������� �������
        morseMap['�'] = ".-";
        morseMap['�'] = "-...";
        morseMap['�'] = ".--";
        morseMap['�'] = "--.";
        morseMap['�'] = "-..";
        morseMap['�'] = ".";
        morseMap['�'] = "...-";
        morseMap['�'] = "--..";
        morseMap['�'] = "..";
        morseMap['�'] = ".---";
        morseMap['�'] = "-.-";
        morseMap['�'] = ".-..";
        morseMap['�'] = "--";
        morseMap['�'] = "-.";
        morseMap['�'] = "---";
        morseMap['�'] = ".--.";
        morseMap['�'] = ".-.";
        morseMap['�'] = "...";
        morseMap['�'] = "-";
        morseMap['�'] = "..-";
        morseMap['�'] = "..-.";
        morseMap['�'] = "....";
        morseMap['�'] = "-.-.";
        morseMap['�'] = "---.";
        morseMap['�'] = "----";
        morseMap['�'] = "--.-";
        morseMap['�'] = ".--.-.";
        morseMap['�'] = "-.--";
        morseMap['�'] = "-..-";
        morseMap['�'] = "..-..";
        morseMap['�'] = "..--";
        morseMap['�'] = ".-.-";
    }

public:
    MorseConverter() {
        InitializeMap();
        setlocale(LC_ALL, "Russian");
    }

    string ConvertToMorse(const string& text) {
        if (text.empty()) {
            cerr << "������: ������� ������ �� ����� ���� ������" << endl;
            return "";
        }

        string converted;
        string upperText = text;
        transform(upperText.begin(), upperText.end(), upperText.begin(), ::toupper);

        for (char c : upperText) {
            if (c == ' ') continue;

            auto morseIt = morseMap.find(c);
            if (morseIt == morseMap.end()) {
                cerr << "������: ��������� ���������������� ������: " << c << endl;
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