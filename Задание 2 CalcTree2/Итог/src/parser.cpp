#include "include/parser.h"

using namespace std;

namespace Parser {
    namespace {
        int GetOpCode(const string& op) {
            if (op == "+") return -1;
            if (op == "-") return -2;
            if (op == "*") return -3;
            if (op == "/") return -4;
            cerr << "Invalid operator: " << op << endl;
            exit(EXIT_FAILURE);
        }
    }

    vector<string> ReadTokens(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Failed to open file: " << filename << endl;
            exit(EXIT_FAILURE);
        }

        vector<string> tokens;
        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            string token;
            while (iss >> token) {
                tokens.push_back(token);
            }
        }
        return tokens;
    }

    Node* BuildExpressionTree(const vector<string>& tokens) {
        stack<Node*> stack;

        for (const auto& token : tokens) {
            if (token.empty()) continue;

            if (isdigit(token[0])) {
                try {
                    int num = stoi(token);
                    if (num < 0 || num > 9) {
                        cerr << "Number out of 0-9 range: " << token << endl;
                        exit(EXIT_FAILURE);
                    }
                    stack.push(new Node(num));
                }
                catch (const exception& e) {
                    cerr << "Invalid number: " << token << endl;
                    exit(EXIT_FAILURE);
                }
            }
            else {
                if (stack.size() < 2) {
                    cerr << "Not enough operands for operator: " << token << endl;
                    exit(EXIT_FAILURE);
                }

                Node* right = stack.top();
                stack.pop();
                Node* left = stack.top();
                stack.pop();

                Node* opNode = new Node(GetOpCode(token));
                opNode->left = left;
                opNode->right = right;
                stack.push(opNode);
            }
        }

        if (stack.size() != 1) {
            cerr << "Invalid postfix expression structure" << endl;
            exit(EXIT_FAILURE);
        }
        return stack.top();
    }
}