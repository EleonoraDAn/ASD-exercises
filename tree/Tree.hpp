#ifndef TREE_HPP
#define TREE_HPP
#include <iostream>
#include <vector>
#include "Node.hpp"

template <typename T>
class Tree
{
private:
    Node<T>* root;
public:
    Tree():root(nullptr){}
    ~Tree();
};




#endif