/**
 * @file processor.h
 * @brief Header file for expression processing functionality
 */

#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <string>
#include <iostream>
#include <stdexcept>
#include "node.h"

using namespace std;

/**
 * @brief Processes mathematical expressions from a file and constructs an Abstract Syntax Tree (AST)
 *
 * This function reads a file containing mathematical expressions, parses the contents,
 * and builds an AST representation of the expressions. The file should contain
 * valid mathematical expressions in a supported format.
 *
 * @param filename Path to the input file containing mathematical expressions
 * @return Node* Pointer to the root node of the constructed AST
 * @throw invalid_argument If the file cannot be opened or is empty
 * @throw runtime_error If a parsing error occurs during AST construction
 *
 * @note The caller is responsible for managing the memory of the returned AST
 * @note Uses standard namespace for string and exception handling
 */

Node* processExpressionFile(const string& filename);

#endif // PROCESSOR_H