/**
 * @file Node.h
 * @brief Definition of a binary expression tree node structure.
 */

#ifndef NODE_H
#define NODE_H

 /**
  * @brief Represents a node in a binary expression tree.
  *
  * Can store either numeric operands (0-9) or arithmetic operators using special codes.
  * Provides recursive memory management through destructor.
  */
struct Node {
    int value; /**<
                * Node value:
                * - 0-9 ��� ���������
                * - ���� ��������:
                *   - -1: '+'
                *   - -2: '-'
                *   - -3: '*'
                *   - -4: '/'
                */
    Node* left;  /**< ����� �������� ���� (nullptr ��� �������) */
    Node* right; /**< ������ �������� ���� (nullptr ��� �������) */

    /**
     * @brief ������������ ���� � �������� ���������
     * @param val �������� ����. ������ ���� � ���������:
     *            - 0-9 ��� ���������
     *            - -1..-4 ��� ����������
     */
    explicit Node(int val);

    /**
     * @brief ���������� ������� ���������
     * @details ������������� ����������� ������ �������� �����
     */
    ~Node();
};

#endif // NODE_H