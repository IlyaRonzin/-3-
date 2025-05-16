/**
 * @file graph.h
 * @brief ����� ��� ������������� ����� ����� ������� ���������
 */

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;

 /**
  * @class Graph
  * @brief ���������� ���������������� ����� � �������������� ������� ���������
  *
  * ����� ������������� ���������� ���:
  * - ���������� ����� ��������� �������
  * - �������� ������� ��������� �� ������
  * - ������� � �������� �����
  */
class Graph {
public:
    /**
     * @brief ����������� �����
     * @param size ���������� ������ � ����� (�� ��������� 0)
     * @details ������� ������� ��������� �������� size x size, ������������������ false
     */
    explicit Graph(size_t size = 0);

    /**
     * @brief �������� ������� ��������� �� ������
     * @param in ������� ����� ��� ������ ������
     * @throw std::runtime_error ��� ������� ������� ������
     * @details ������ ������: ������������������ 0 � 1, ���������� ���������
     */
    void load_from_stream(istream& in);

    /**
     * @brief ������ � ������ ������� ���������
     * @param index ����� ������� (������� � 0)
     * @return ����������� ������ �� ������ ��������� ��� ��������� �������
     * @throw std::out_of_range ��� ������ �� ������� �������
     */
    const std::vector<bool>& operator[](size_t index) const;

    /**
     * @brief ��������� ������� �����
     * @return ���������� ������ � �����
     */
    size_t size() const noexcept;

private:
    /// ������� ��������� (true - ������� �����, false - ����������)
    vector<vector<bool>> adjacency_matrix;
};

#endif // GRAPH_H