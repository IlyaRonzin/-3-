/**
 * @file MorseConverter.h
 * @brief ������������ ���� ��� ������ MorseConverter, ���������������� ��� �������������� �������� ������ � ������ �����.
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
 * @brief ����� ��� ����������� �������������� ������ � ������������������ �������� ������ �����.
 *
 * ������������ ������� �������� �������� (�-�), ���������� �������.
 * ���������������� ������� �������� ����� ������ � stderr.
 */
class MorseConverter {
private:
    map<char, string> morseMap; ///< ����� ������������ ������� �������� � �� ������������� � �����.

    /**
     * @brief �������������� ����� morseMap �������� ��������� � �� ������ �����.
     */
    void InitializeMap();

public:
    /**
     * @brief ����������� �� ���������.
     * @note ������������� ������ "Russian" ��� ���������� ��������� ��������.
     */
    MorseConverter();

    /**
     * @brief ������������ ������� ������ � ������ �����.
     *
     * @param text ������� ������ �� ������� �����. ������� �������� �� ����� (������������� ������������� � �������).
     * @return ������ � ������������������� ����� �����, ����������� ���������.
     * @note ������ �������������:
     * @code
     * MorseConverter converter;
     * string morse = converter.convertToMorse("������");
     * @endcode
     *
     * @warning ��� ����������� ����������������� ������� ������� ������ � cerr � ���������� ������ ������.
     * @warning ������ ������� ������ ����� �������� ������ ����� cerr.
     */
    string ConvertToMorse(const string& text);
};

#endif // MORSECONVERTER_H