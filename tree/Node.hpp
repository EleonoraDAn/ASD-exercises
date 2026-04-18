#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>

template <typename T>
class Node
{
private:
    T value;
    Node<T>* left;
    Node<T>* right;
    Node<T>* parent;
public:
    Node(T value) {
        this->value = value;
        left = right = parent = nullptr;
    }

    Node<T>* getLeft() {
        return left;
    }

    Node<T>* getRight() {
        return right;
    }

    Node<T>* getParent() {
        return parent;
    }

    void setLeft(Node<T>* &l) {
        left = l;
    }

    void setRight(Node<T>* &r) {
        right = r;
    }

    void setParent(Node<T>* &p) {
        parent = p;
    }

    T getValue() {
        return value;
    }

    void setValue(T value) {
        this->value = value;
    }

    ~Node() {}
};


#endif