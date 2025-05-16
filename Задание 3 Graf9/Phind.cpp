#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Route {
    vector<int> path;
    int transfers;
};

bool operator<(const Route& r1, const Route& r2) {
    return r1.path < r2.path;
}

vector<Route> findRoutesWithTransfers(const vector<vector<bool>>& graph, 
                                    int start, int finish, int maxTransfers) {
    vector<Route> validRoutes;
    vector<int> currentPath;
    currentPath.reserve(maxTransfers + 2);
    
    function<void(int, int)> dfs = [&](int currentCity, int transfersUsed) {
        currentPath.push_back(currentCity);
        
        if (currentCity == finish && transfersUsed <= maxTransfers) {
            validRoutes.push_back({currentPath, transfersUsed});
            currentPath.pop_back();
            return;
        }
        
        if (transfersUsed >= maxTransfers) {
            currentPath.pop_back();
            return;
        }
        
        for (int nextCity = 0; nextCity < graph.size(); ++nextCity) {
            if (graph[currentCity][nextCity]) {
                dfs(nextCity, transfersUsed + 1);
            }
        }
        
        currentPath.pop_back();
    };
    
    dfs(start, 0);
    sort(validRoutes.begin(), validRoutes.end());
    return validRoutes;
}

int main() {
    ifstream inputFile("FileName1");
    ofstream outputFile("FileName2");
    
    if (!inputFile.is_open()) {
        cerr << "Ошибка открытия входного файла!" << endl;
        return 1;
    }
    
    int n;
    inputFile >> n;
    
    if (n <= 0 || n > 15) {
        cerr << "Неверное количество городов!" << endl;
        return 1;
    }
    
    vector<vector<bool>> graph(n, vector<bool>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int val;
            inputFile >> val;
            graph[i][j] = (val == 1);
        }
    }
    
    int K1, K2, L;
    inputFile >> K1 >> K2 >> L;
    
    if (K1 < 1 || K1 > n || K2 < 1 || K2 > n || L < 0) {
        cerr << "Неверные параметры маршрута!" << endl;
        return 1;
    }
    
    --K1; --K2; // Приводим индексы к 0-based
    
    vector<Route> routes = findRoutesWithTransfers(graph, K1, K2, L);
    
    if (routes.empty()) {
        outputFile << "-1\n";
    } else {
        outputFile << routes.size() << "\n";
        for (const auto& route : routes) {
            for (size_t i = 0; i < route.path.size(); ++i) {
                outputFile << (route.path[i] + 1);
                if (i < route.path.size() - 1) {
                    outputFile << " ";
                }
            }
            outputFile << "\n";
        }
    }
    
    inputFile.close();
    outputFile.close();
    return 0;
}