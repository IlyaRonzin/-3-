#include <iostream>
#include <fstream>
#include <stack>
#include <string>

// Структура узла дерева выражений
struct Node {
    int value;           // значение узла (цифра или код операции)
    Node* left;         // левый потомок
    Node* right;        // правый потомок
    
    Node(int val = 0) : value(val), left(nullptr), right(nullptr) {}
    
    ~Node() {
        delete left;
        delete right;
    }
};

// Функция для получения кода операции
int getOperationCode(char op) {
    switch (op) {
        case '+': return -1;
        case '-': return -2;
        case '*': return -3;
        case '/': return -4;
        default: throw std::runtime_error("Неверная операция");
    }
}

// Построение дерева из постфиксной нотации
Node* buildTree(const std::string& expression) {
    std::stack<Node*> st;
    
    for (char c : expression) {
        Node* newNode = nullptr;
        
        // Если символ - цифра
        if (isdigit(c)) {
            newNode = new Node(c - '0');
            st.push(newNode);
        }
        // Если символ - операция
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int opCode = getOperationCode(c);  // Преобразуем операцию в код
            
            newNode = new Node(opCode);
            
            newNode->right = st.top(); st.pop();
            newNode->left = st.top(); st.pop();
            
            st.push(newNode);
        }
    }
    
    return st.top();
}

// Оценка значения поддерева
int evaluateSubtree(Node* node) {
    if (!node) return 0;
    
    if (node->value >= 0) return node->value;  // Цифра
    
    int leftVal = evaluateSubtree(node->left);
    int rightVal = evaluateSubtree(node->right);
    
    switch (node->value) {
        case -1: return leftVal + rightVal;
        case -2: return leftVal - rightVal;
        case -3: return leftVal * rightVal;
        case -4: return leftVal / rightVal;
        default: throw std::runtime_error("Неверная операция");
    }
}

// Преобразование дерева для устранения сложения
Node* transformTree(Node* root) {
    if (!root) return nullptr;
    
    root->left = transformTree(root->left);
    root->right = transformTree(root->right);
    
    // Если узел содержит операцию сложения (-1)
    if (root->value == -1) {
        int result = evaluateSubtree(root);
        delete root->left;
        delete root->right;
        delete root;
        
        root = new Node(result);
    }
    
    return root;
}

// Основная функция решения задачи
Node* calcTree2(const std::string& filename) {
    std::ifstream fin(filename);
    if (!fin) throw std::runtime_error("Ошибка открытия файла");
    
    std::string expression;
    getline(fin, expression);
    fin.close();
    
    Node* root = buildTree(expression);
    root = transformTree(root);
    
    return root;
}

int main() {
    try {
        std::string filename;
        std::cout << "Введите имя файла: ";
        std::cin >> filename;
        
        Node* root = calcTree2(filename);
        if (root) {
            std::cout << "Дерево успешно построено и преобразовано." << std::endl;
            std::cout << "Корневой узел содержит значение: " << root->value << std::endl;
            
            delete root;
        }
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}