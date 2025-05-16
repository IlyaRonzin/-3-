#include "include/node.h"

Node::Node(int val) : value(val), left(nullptr), right(nullptr) {}

Node::~Node() {
    delete left;
    delete right;
}