/**
 * @file route.h
 * @brief Заголовочный файл для работы с маршрутами в графе
 */

#ifndef ROUTE_H
#define ROUTE_H

#include <vector>
#include <algorithm>
#include "graph.h"

using namespace std;

 /**
  * @struct Route
  * @brief Структура для представления маршрута между городами
  *
  * Содержит последовательность городов в порядке прохождения и оператор сравнения
  * для лексикографической сортировки маршрутов
  */
struct Route {
    vector<int> cities; ///< Вектор номеров городов (1-based индексация)

    /**
     * @brief Оператор сравнения маршрутов
     * @param other Сравниваемый маршрут
     * @return true если текущий маршрут лексикографически меньше other
     */
    bool operator<(const Route& other) const {
        return cities < other.cities;
    }
};

/**
 * @class RouteFinder
 * @brief Класс для поиска всех маршрутов с заданным числом пересадок
 *
 * Реализует алгоритм DFS для поиска маршрутов между указанными городами
 * с ограничением по максимальному числу пересадок
 */
class RouteFinder {
public:
    /**
     * @brief Конструктор инициализации поисковика маршрутов
     * @param graph Ссылка на объект графа
     * @param start Начальный город (1-based)
     * @param end Конечный город (1-based)
     * @param max_transfers Максимальное допустимое число пересадок
     */
    RouteFinder(const Graph& graph, int start, int end, int max_transfers);

    /**
     * @brief Основной метод поиска маршрутов
     * @return Константная ссылка на вектор найденных маршрутов
     * @note Результаты автоматически сортируются лексикографически
     */
    const vector<Route>& find_routes();

private:
    /**
     * @brief Вспомогательный метод DFS для рекурсивного поиска
     * @param current Текущий город (0-based индекс)
     * @param transfers_used Использованное число пересадок
     * @param path Текущий накопленный путь (1-based индексация)
     */
    void dfs(int current, int transfers_used, vector<int>& path);

    const Graph& graph;         ///< Ссылка на граф для поиска
    const int start;            ///< Стартовый город (0-based)
    const int end;              ///< Целевой город (0-based)
    const int max_transfers;    ///< Максимальное число пересадок
    vector<Route> routes;  ///< Найденные маршруты
};

#endif // ROUTE_H