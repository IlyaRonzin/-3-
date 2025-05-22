/**
 * @file transformer.h
 * @brief Declarations for AST transformation functions.
 */

#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include <stdexcept>
#include <cstdlib>
#include "node.h"

using namespace std;

/**
 * @namespace Transformer
 * @brief Contains operations for transforming abstract syntax trees (AST)
 *
 * This namespace provides functionality to perform semantic-preserving
 * transformations on abstract syntax trees, such as operation substitutions
 * and structural optimizations.
 */
namespace Transformer {
    /**
     * @brief Replaces addition nodes with equivalent operations in the AST
     *
     * Traverses the AST and substitutes all addition operations (NodeType::ADD)
     * with equivalent representations according to transformation rules.
     *
     * @param root Pointer to the root node of the AST to transform
     * @return Node* New root of the modified AST (may be same as input root)
     * @throws std::invalid_argument If null root is provided
     *
     * @warning The original tree may be modified. Caller should assume ownership
     * of the returned tree structure.
     */
    Node* ReplaceAddition(Node* root);
}

#endif // TRANSFORMER_H