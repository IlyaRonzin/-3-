/**
 * @file utils.h
 * @brief ��������������� ������� ��� ��������� ������� ������
 */

#ifndef UTILS_H
#define UTILS_H

#include <stdexcept>
#include <string>

 /**
  * @brief ��������� ������������ ������� ���������� ������
  * @param cities ����� ���������� ������� (������ ���� 1-15)
  * @param start ��������� ����� �������� (1-based ������)
  * @param end �������� ����� �������� (1-based ������)
  * @param transfers ���������� ���������� ��������� (���������������)
  * @throw std::invalid_argument ��� ��������� ������ �� ������� ���������
  *
  * ������� ��������� ��������� ��������:
  * - ���������� ������� � ���������� ���������
  * - ������������ ������� ����������/��������� ������
  * - �������������� �������������� ����� ���������
  */
void ValidateInput(int cities, int start, int end, int transfers);

#endif // UTILS_H