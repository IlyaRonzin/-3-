#include <fstream>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

vector<string> readTokens(const string& filename) {
    ifstream file(filename);
    vector<string> tokens;
    string line;
    if (file.is_open()) {
        getline(file, line);
        stringstream ss(line);
        string token;
        while (ss >> token) {
            tokens.push_back(token);
        }
        file.close();
    }
    return tokens;
}

Node* buildTree(const vector<string>& tokens) {
    stack<Node*> st;
    for (const string& token : tokens) {
        if (token == "+") {
            Node* node = new Node(-1);
            Node* right = st.top(); st.pop();
            Node* left = st.top(); st.pop();
            node->left = left;
            node->right = right;
            st.push(node);
        } else if (token == "-") {
            Node* node = new Node(-2);
            Node* right = st.top(); st.pop();
            Node* left = st.top(); st.pop();
            node->left = left;
            node->right = right;
            st.push(node);
        } else if (token == "*") {
            Node* node = new Node(-3);
            Node* right = st.top(); st.pop();
            Node* left = st.top(); st.pop();
            node->left = left;
            node->right = right;
            st.push(node);
        } else if (token == "/") {
            Node* node = new Node(-4);
            Node* right = st.top(); st.pop();
            Node* left = st.top(); st.pop();
            node->left = left;
            node->right = right;
            st.push(node);
        } else {
            int num = stoi(token);
            st.push(new Node(num));
        }
    }
    return st.empty() ? nullptr : st.top();
}

Node* replaceAddition(Node* node) {
    if (!node) return nullptr;
    if (!node->left && !node->right) {
        return node;
    }
    node->left = replaceAddition(node->left);
    node->right = replaceAddition(node->right);
    if (node->value == -1) {
        int sum = node->left->value + node->right->value;
        delete node->left;
        delete node->right;
        Node* newNode = new Node(sum);
        delete node;
        return newNode;
    }
    return node;
}

// Пример использования (не требуется в задаче, для демонстрации)
// int main() {
//     Node* root = buildTree(readTokens("input.txt"));
//     root = replaceAddition(root);
//     return 0;
// }