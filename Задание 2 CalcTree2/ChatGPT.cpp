#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <string>

struct Node {
    int value;       // от 0 до 9 или -1: '+' -2: '-' -3: '*' -4: '/'
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Вычисляет значение поддерева
int evaluate(Node* node) {
    if (!node->left && !node->right)
        return node->value;

    int l = evaluate(node->left);
    int r = evaluate(node->right);

    switch (node->value) {
        case -1: return l + r;
        case -2: return l - r;
        case -3: return l * r;
        case -4: return l / r;
    }
    return 0; // should not reach here
}

// Заменяет + на числовое значение
Node* transform(Node* node) {
    if (!node) return nullptr;

    node->left = transform(node->left);
    node->right = transform(node->right);

    if (node->value == -1) {
        int val = evaluate(node);
        delete node->left;
        delete node->right;
        return new Node(val);
    }

    return node;
}

// Построение дерева из постфиксного выражения
Node* buildTree(const std::string& postfix) {
    std::stack<Node*> stk;
    std::istringstream iss(postfix);
    std::string token;

    while (iss >> token) {
        if (isdigit(token[0])) {
            stk.push(new Node(token[0] - '0'));
        } else {
            int opCode;
            if (token == "+") opCode = -1;
            else if (token == "-") opCode = -2;
            else if (token == "*") opCode = -3;
            else if (token == "/") opCode = -4;
            else continue;

            Node* right = stk.top(); stk.pop();
            Node* left = stk.top(); stk.pop();

            Node* node = new Node(opCode);
            node->left = left;
            node->right = right;
            stk.push(node);
        }
    }

    return stk.empty() ? nullptr : stk.top();
}

int main() {
    std::ifstream fin("filename");
    std::string line, expression;
    while (std::getline(fin, line)) {
        expression += line + " ";
    }

    Node* root = buildTree(expression);
    root = transform(root);

    std::cout << "Pointer to root: " << root << std::endl;

    return 0;
}
