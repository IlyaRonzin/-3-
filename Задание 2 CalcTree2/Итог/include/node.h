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
                * - 0-9 для операндов
                * - Коды операций:
                *   - -1: '+'
                *   - -2: '-'
                *   - -3: '*'
                *   - -4: '/'
                */
    Node* left;  /**< Левый дочерний узел (nullptr для листьев) */
    Node* right; /**< Правый дочерний узел (nullptr для листьев) */

    /**
     * @brief Конструирует узел с заданным значением
     * @param val Значение узла. Должно быть в диапазоне:
     *            - 0-9 для операндов
     *            - -1..-4 для операторов
     */
    explicit Node(int val);

    /**
     * @brief Рекурсивно удаляет поддерево
     * @details Автоматически освобождает память дочерних узлов
     */
    ~Node();
};

#endif // NODE_H