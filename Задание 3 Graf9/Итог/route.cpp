#include "route.h"

RouteFinder::RouteFinder(const Graph& graph, int start, int end, int max_transfers)
    : graph(graph), start(start - 1), end(end - 1), max_transfers(max_transfers) {}

const vector<Route>& RouteFinder::find_routes() {
    vector<int> path;
    path.reserve(max_transfers + 1);
    path.push_back(start + 1); // Храним 1-based
    dfs(start, 0, path);
    sort(routes.begin(), routes.end());
    return routes;
}

void RouteFinder::dfs(int current, int transfers_used, vector<int>& path) {
    if (current == end && transfers_used == max_transfers) {
        routes.push_back({ path });
    }

    if (transfers_used < max_transfers) {
        for (int next = 0; next < static_cast<int>(graph.size()); ++next) {
            if (graph[current][next]) {
                path.push_back(next + 1);
                dfs(next, transfers_used + 1, path);
                path.pop_back();
            }
        }
    }
}