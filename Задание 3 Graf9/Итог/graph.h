/**
 * @file graph.h
 * @brief Класс для представления графа через матрицу смежности
 */

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;

 /**
  * @class Graph
  * @brief Реализация ориентированного графа с использованием матрицы смежности
  *
  * Класс предоставляет функционал для:
  * - Созранения графа заданного размера
  * - Загрузки матрицы смежности из потока
  * - Доступа к вершинам графа
  */
class Graph {
public:
    /**
     * @brief Конструктор графа
     * @param size Количество вершин в графе (по умолчанию 0)
     * @details Создает матрицу смежности размером size x size, инициализированную false
     */
    explicit Graph(size_t size = 0);

    /**
     * @brief Загрузка матрицы смежности из потока
     * @param in Входной поток для чтения данных
     * @throw std::runtime_error При ошибках формата данных
     * @details Формат данных: последовательность 0 и 1, разделённых пробелами
     */
    void load_from_stream(istream& in);

    /**
     * @brief Доступ к строке матрицы смежности
     * @param index Номер вершины (начиная с 0)
     * @return Константная ссылка на вектор смежности для указанной вершины
     * @throw std::out_of_range При выходе за границы матрицы
     */
    const std::vector<bool>& operator[](size_t index) const;

    /**
     * @brief Получение размера графа
     * @return Количество вершин в графе
     */
    size_t size() const noexcept;

private:
    /// Матрица смежности (true - наличие ребра, false - отсутствие)
    vector<vector<bool>> adjacency_matrix;
};

#endif // GRAPH_H