#include "graph.h"

Graph::Graph(size_t size) : adjacency_matrix(size, vector<bool>(size)) {}

void Graph::LoadFromStream(istream& in) {
    for (auto& row : adjacency_matrix) {
        for (size_t j = 0; j < row.size(); ++j) {
            int value;
            if (!(in >> value)) {
                cerr << "������ ������ �������� ������� ["
                    << (&row - &adjacency_matrix[0]) << "]["
                    << j << "]" << endl;
                throw runtime_error("������ ������� ������� ������");
            }
            row[j] = (value == 1);
        }
    }
}

const vector<bool>& Graph::operator[](size_t index) const {
    try {
        return adjacency_matrix.at(index);
    }
    catch (const out_of_range& e) {
        cerr << "������� ������� � ��������������� �������: " << index << endl;
        throw;
    }
}

size_t Graph::size() const noexcept {
    return adjacency_matrix.size();
}