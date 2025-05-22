/**
 * @file MorseConverter.h
 * @brief Заголовочный файл для класса MorseConverter, предназначенного для преобразования русского текста в азбуку Морзе.
 */

#ifndef MORSECONVERTER_H
#define MORSECONVERTER_H

#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <locale>

using namespace std;

/**
 * @class MorseConverter
 * @brief Класс для конвертации русскоязычного текста в последовательность символов азбуки Морзе.
 *
 * Поддерживает символы русского алфавита (А-Я), игнорирует пробелы.
 * Неподдерживаемые символы вызывают вывод ошибки в stderr.
 */
class MorseConverter {
private:
    map<char, string> morseMap; ///< Карта соответствия русских символов и их представления в Морзе.

    /**
     * @brief Инициализирует карту morseMap русскими символами и их кодами Морзе.
     */
    void InitializeMap();

public:
    /**
     * @brief Конструктор по умолчанию.
     * @note Устанавливает локаль "Russian" для корректной обработки символов.
     */
    MorseConverter();

    /**
     * @brief Конвертирует входную строку в азбуку Морзе.
     *
     * @param text Входная строка на русском языке. Регистр символов не важен (автоматически преобразуется в верхний).
     * @return Строка с последовательностью кодов Морзе, разделенных пробелами.
     * @note Пример использования:
     * @code
     * MorseConverter converter;
     * string morse = converter.convertToMorse("Привет");
     * @endcode
     *
     * @warning При обнаружении неподдерживаемого символа выводит ошибку в cerr и возвращает пустую строку.
     * @warning Пустая входная строка также вызывает ошибку через cerr.
     */
    string ConvertToMorse(const string& text);
};

#endif // MORSECONVERTER_H