#include "graph.h"
#include "route.h"
#include "utils.h"

int main(int argc, char* argv[]) {
    try {
        if (argc != 3) {
            throw runtime_error("Использование: program input.txt output.txt");
        }

        ifstream in(argv[1]);
        ofstream out(argv[2]);

        if (!in) throw runtime_error("Не удалось открыть входной файл");
        if (!out) throw runtime_error("Не удалось открыть выходной файл");

        int n, K1, K2, L;
        in >> n;
        validate_input(n, 1, 1, 0);

        Graph graph(n);
        graph.load_from_stream(in);

        in >> K1 >> K2 >> L;
        validate_input(n, K1, K2, L);

        RouteFinder finder(graph, K1, K2, L + 1);
        const auto& routes = finder.find_routes();

        if (routes.empty()) {
            out << -1;
        }
        else {
            out << routes.size() << '\n';
            for (const auto& route : routes) {
                for (size_t i = 0; i < route.cities.size(); ++i) {
                    if (i > 0) out << ' ';
                    out << route.cities[i];
                }
                out << '\n';
            }
        }
    }
    catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
        return 1;
    }

    return 0;
}