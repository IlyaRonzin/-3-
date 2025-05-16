#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<vector<int>> readMatrix(ifstream& in, int n) {
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            in >> matrix[i][j];
        }
    }
    return matrix;
}

void dfs(int current, vector<int>& path, int steps, int required_steps, int target, const vector<vector<int>>& matrix, vector<vector<int>>& result) {
    if (steps == required_steps) {
        if (current == target) {
            result.push_back(path);
        }
        return;
    }
    vector<int> neighbors;
    for (int next = 0; next < matrix.size(); ++next) {
        if (matrix[current][next]) {
            neighbors.push_back(next);
        }
    }
    sort(neighbors.begin(), neighbors.end(), [](int a, int b) {
        return (a + 1) < (b + 1);
    });
    for (int next : neighbors) {
        path.push_back(next + 1);
        dfs(next, path, steps + 1, required_steps, target, matrix, result);
        path.pop_back();
    }
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        return 1;
    }
    string filename1 = argv[1];
    string filename2 = argv[2];

    ifstream in(filename1);
    ofstream out(filename2);

    int n, K1, K2, L;
    in >> n;
    auto matrix = readMatrix(in, n);
    in >> K1 >> K2 >> L;

    int k1 = K1 - 1;
    int k2 = K2 - 1;
    int required_steps = L + 1;

    vector<vector<int>> result;
    vector<int> path = {K1};
    dfs(k1, path, 0, required_steps, k2, matrix, result);

    if (result.empty()) {
        out << -1 << endl;
    } else {
        out << result.size() << endl;
        for (const auto& p : result) {
            for (size_t i = 0; i < p.size(); ++i) {
                if (i > 0) {
                    out << " ";
                }
                out << p[i];
            }
            out << endl;
        }
    }

    return 0;
}