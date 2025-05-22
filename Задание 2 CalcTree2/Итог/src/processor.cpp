#include "include/processor.h"
#include "include/parser.h"
#include "include/transformer.h"

Node* ProcessExpressionFile(const string& filename) {
    auto tokens = Parser::ReadTokens(filename);
    Node* root = Parser::BuildExpressionTree(tokens);
    return Transformer::ReplaceAddition(root);
}