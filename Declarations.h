#ifndef BINARY_SEARCH_TREE_DECLARATIONS_H
#define BINARY_SEARCH_TREE_DECLARATIONS_H
#include <iostream>
using namespace std;
#define COUNT 10

template<typename T>
struct Node{
    T key;
    Node* left_child;
    Node* right_child;
    explicit  Node(T _key):key(_key),left_child(nullptr),right_child(nullptr){}
};
#include "Implementations.hpp"
#endif //BINARY_SEARCH_TREE_DECLARATIONS_H
