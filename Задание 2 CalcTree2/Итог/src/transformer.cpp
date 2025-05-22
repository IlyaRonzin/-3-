#include "include/transformer.h"

using namespace std;

namespace Transformer {
    namespace {
        int EvaluateSubtree(Node* node) {
            if (!node) {
                cerr << "Null node in evaluation" << endl;
                exit(EXIT_FAILURE);
            }

            if (!node->left && !node->right) {
                if (node->value < 0) {
                    cerr << "Invalid numeric node value: " << node->value << endl;
                    exit(EXIT_FAILURE);
                }
                return node->value;
            }

            if (!node->left || !node->right) {
                cerr << "Incomplete operator node" << endl;
                exit(EXIT_FAILURE);
            }

            int left = EvaluateSubtree(node->left);
            int right = EvaluateSubtree(node->right);

            switch (node->value) {
            case -1: return left + right;
            case -2: return left - right;
            case -3: return left * right;
            case -4:
                if (right == 0) {
                    cerr << "Division by zero" << endl;
                    exit(EXIT_FAILURE);
                }
                return left / right;
            default:
                cerr << "Unknown operator code: " << node->value << endl;
                exit(EXIT_FAILURE);
            }
        }
    }

    Node* ReplaceAddition(Node* root) {
        if (!root) return nullptr;

        root->left = ReplaceAddition(root->left);
        root->right = ReplaceAddition(root->right);

        if (root->value == -1) {
            int result = EvaluateSubtree(root);
            delete root->left;
            delete root->right;
            return new Node(result);
        }
        return root;
    }
}