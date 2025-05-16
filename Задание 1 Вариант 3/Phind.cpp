#include <iostream>
#include <string>
#include <map>

using namespace std;

class MorseTelegraph {
private:
    map<char, string> rusToMorse;

public:
    MorseTelegraph() {
        // Инициализация словаря русской азбуки Морзе
        rusToMorse['А'] = ".-";
        rusToMorse['Б'] = "-...";
        rusToMorse['В'] = ".---";
        rusToMorse['Г'] = "--.";
        rusToMorse['Д'] = "-..";
        rusToMorse['Е'] = ".";
        rusToMorse['Ж'] = "...-";
        rusToMorse['З'] = "--..";
        rusToMorse['И'] = "..";
        rusToMorse['Й'] = ".---";
        rusToMorse['К'] = "-.-";
        rusToMorse['Л'] = ".-..";
        rusToMorse['М'] = "--";
        rusToMorse['Н'] = "-.";
        rusToMorse['О'] = "---";
        rusToMorse['П'] = ".--.";
        rusToMorse['Р'] = ".-.";
        rusToMorse['С'] = "...";
        rusToMorse['Т'] = "-";
        rusToMorse['У'] = "..-";
        rusToMorse['Ф'] = "..-.";
        rusToMorse['Х'] = "....";
        rusToMorse['Ц'] = "-.-.";
        rusToMorse['Ч'] = "---.";
        rusToMorse['Ш'] = "----";
        rusToMorse['Щ'] = "--.--";
        rusToMorse['Ъ'] = ".--.-.";
        rusToMorse['Ы'] = "-.--";
        rusToMorse['Ь'] = "-..-";
        rusToMorse['Э'] = "..-..";
        rusToMorse['Ю'] = "..---";
        rusToMorse['Я'] = ".-.";
    }

    string encode(const string& text) {
        string morse;
        for (char c : text) {
            // Пропускаем пробелы и неизвестные символы
            if (rusToMorse.find(c) != rusToMorse.end()) {
                morse += rusToMorse[c] + " ";
            }
        }
        return morse;
    }

    void printMessage(const string& morseText) {
        cout << "\nСообщение в азбуке Морзе:\n";
        cout << morseText << endl;
        
        // Выводим каждую букву отдельно для наглядности
        size_t pos = 0;
        while ((pos = morseText.find(" ")) != string::npos) {
            cout << morseText.substr(0, pos) << " ";
            morseText.erase(0, pos + 1);
        }
        cout << endl;
    }
};

int main() {
    MorseTelegraph telegraph;
    
    cout << "Введите сообщение на русском языке: ";
    string message;
    getline(cin, message);

    string morseMessage = telegraph.encode(message);
    telegraph.printMessage(morseMessage);

    return 0;
}