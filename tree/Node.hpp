#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>
template<typename T>
class Node
{
private:
    T value;
    Node<T>* right;
    Node<T>* left;
    Node<T>* parent;
public:
    Node(T v):left(nullptr), right(nullptr), parent(nullptr), value(v) {}
    void setLeft(Node<T>* l) {
        left = l;
    }
    void setRight(Node<T>* r) {
        right = r;
    }
    void setParent(Node<T>* p) {
        parent = p;
    }
    void setValue(T v) {
        value = v;
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
    T getValue() {
        return value;
    }
    ~Node() {}
};


#endif