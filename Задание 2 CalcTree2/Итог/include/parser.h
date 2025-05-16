/**
 * @file parser.h
 * @brief Provides functions for parsing tokens and building expression trees.
 *
 * This header defines the Parser namespace containing utilities for reading tokens
 * from files and constructing binary expression trees from those tokens.
 */

#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <stack>
#include <cctype>
#include <cstdlib>
#include "node.h"

using namespace std;

/**
 * @namespace Parser
 * @brief Contains token processing and expression tree construction functionality
 */
namespace Parser {
    /**
     * @brief Reads whitespace-separated tokens from a text file
     * @param filename Path to the input file containing tokens
     * @return vector<string> Ordered sequence of tokens from the file
     * @throws runtime_error If file cannot be opened
     *
     * @par Example:
     * @code
     * vector<string> tokens = Parser::readTokens("input.txt");
     * @endcode
     */
    vector<string> readTokens(const string& filename);

    /**
     * @brief Builds a binary expression tree from postfix tokens
     * @param tokens Sequence of operands and operators in postfix order
     * @return Node* Root node of the constructed expression tree
     * @throws invalid_argument If invalid postfix expression format
     *
     * @par Algorithm:
     * Uses a stack-based approach where operands create leaf nodes,
     * and operators combine the top 2 nodes from the stack
     */
    Node* buildExpressionTree(const vector<string>& tokens);
}

#endif // PARSER_H