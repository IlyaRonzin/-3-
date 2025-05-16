#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n; // количество городов
vector<vector<int>> adj; // матрица смежности
vector<vector<int>> routes; // все маршруты
int K1, K2, L;

void dfs(int current, int depth, vector<int>& path, vector<bool>& visited) {
    if (depth > L + 1) return;

    if (depth == L + 1 && current == K2) {
        routes.push_back(path);
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (adj[current][i] == 1) {
            path.push_back(i);
            dfs(i, depth + 1, path, visited);
            path.pop_back();
        }
    }
}

int main() {
    string FileName1 = "input.txt";
    string FileName2 = "output.txt";

    ifstream fin(FileName1);
    ofstream fout(FileName2);

    if (!fin) {
        cerr << "Ошибка открытия файла " << FileName1 << endl;
        return 1;
    }

    fin >> n;
    adj.assign(n, vector<int>(n));
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            fin >> adj[i][j];

    fin >> K1 >> K2 >> L;
    --K1; --K2; // переход к индексации с 0

    vector<int> path = {K1};
    vector<bool> visited(n, false);
    dfs(K1, 1, path, visited);

    if (routes.empty()) {
        fout << -1 << endl;
    } else {
        // Лексикографическая сортировка
        sort(routes.begin(), routes.end());
        fout << routes.size() << endl;
        for (const auto& route : routes) {
            for (int city : route)
                fout << (city + 1) << " ";
            fout << endl;
        }
    }

    return 0;
}
