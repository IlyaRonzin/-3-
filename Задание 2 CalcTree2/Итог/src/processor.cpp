#include "include/processor.h"
#include "include/parser.h"
#include "include/transformer.h"

Node* processExpressionFile(const string& filename) {
    auto tokens = Parser::readTokens(filename);
    Node* root = Parser::buildExpressionTree(tokens);
    return Transformer::replaceAddition(root);
}