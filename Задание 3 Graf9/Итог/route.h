/**
 * @file route.h
 * @brief ������������ ���� ��� ������ � ���������� � �����
 */

#ifndef ROUTE_H
#define ROUTE_H

#include <vector>
#include <algorithm>
#include "graph.h"

using namespace std;

 /**
  * @struct Route
  * @brief ��������� ��� ������������� �������� ����� ��������
  *
  * �������� ������������������ ������� � ������� ����������� � �������� ���������
  * ��� ������������������ ���������� ���������
  */
struct Route {
    vector<int> cities; ///< ������ ������� ������� (1-based ����������)

    /**
     * @brief �������� ��������� ���������
     * @param other ������������ �������
     * @return true ���� ������� ������� ����������������� ������ other
     */
    bool operator<(const Route& other) const {
        return cities < other.cities;
    }
};

/**
 * @class RouteFinder
 * @brief ����� ��� ������ ���� ��������� � �������� ������ ���������
 *
 * ��������� �������� DFS ��� ������ ��������� ����� ���������� ��������
 * � ������������ �� ������������� ����� ���������
 */
class RouteFinder {
public:
    /**
     * @brief ����������� ������������� ���������� ���������
     * @param graph ������ �� ������ �����
     * @param start ��������� ����� (1-based)
     * @param end �������� ����� (1-based)
     * @param max_transfers ������������ ���������� ����� ���������
     */
    RouteFinder(const Graph& graph, int start, int end, int max_transfers);

    /**
     * @brief �������� ����� ������ ���������
     * @return ����������� ������ �� ������ ��������� ���������
     * @note ���������� ������������� ����������� �����������������
     */
    const vector<Route>& find_routes();

private:
    /**
     * @brief ��������������� ����� DFS ��� ������������ ������
     * @param current ������� ����� (0-based ������)
     * @param transfers_used �������������� ����� ���������
     * @param path ������� ����������� ���� (1-based ����������)
     */
    void dfs(int current, int transfers_used, vector<int>& path);

    const Graph& graph;         ///< ������ �� ���� ��� ������
    const int start;            ///< ��������� ����� (0-based)
    const int end;              ///< ������� ����� (0-based)
    const int max_transfers;    ///< ������������ ����� ���������
    vector<Route> routes;  ///< ��������� ��������
};

#endif // ROUTE_H