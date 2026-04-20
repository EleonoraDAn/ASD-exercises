#ifndef ABR_HPP
#define ABR_HPP
#include <iostream>
#include <vector>
#include "Node.hpp"

template <typename T>
class ABR
{
    private:
        Node<T>* root;
    public:
        ABR():root(nullptr) {}
        Node<T>* getMax(Node<T>* node) {
            while(node->getRight() != nullptr) {
                node = node->getRight();
            }
            return node;
        }

        Node<T>* getMin(Node<T>* node) {
            while(node->getLeft() != nullptr) {
                node = node->getLeft();
            }
            return node;
        }

        void insert(Node<T>* nodoDaInserire) {
            Node<T>* current = root;
            Node<T>* parentNode = nullptr;
            while(current != nullptr) {
                parentNode = current;
                if(nodoDaInserire->getValue() < current->getValue()) {
                    current = current->getLeft();
                } else {
                    current = current->getRight();
                }

            }

            nodoDaInserire->setParent(parentNode);
            if(parentNode == nullptr) {
                root = nodoDaInserire;
            } else if(nodoDaInserire->getValue() < parentNode->getValue()) {
                parentNode->setLeft(nodoDaInserire);
            } else {
                parentNode->setRight(nodoDaInserire);
            }
        }

        
        void transplant(Node<T>* u, Node<T>* v) {
            if(u->getParent() == nullptr) {
                root = v;
            } 

            else if(u == u->getParent()->getLeft()) {
                u->getParent()->setLeft(v);
            } else {
                u->getParent()->setRight(v);
            }

            if(v != nullptr) {
                v->setParent(u->getParent());
            }
        }

        Node<T>* searchNode(T key) {
            Node<T>* current = root;
            while(current != nullptr && key != current->getValue()) {
                if(key < current->getValue()) {
                    current = current->getLeft();
                } else {
                    current = current->getRight();
                }
            }
            return current;
        }

        void deleteNode(T key) {
            Node<T>* nodoDaEliminare = searchNode(key);
            if(nodoDaEliminare == nullptr) {
                return;
            }

            if(nodoDaEliminare->getLeft() == nullptr) {
                transplant(nodoDaEliminare, nodoDaEliminare->getRight());
            } else if(nodoDaEliminare->getRight() == nullptr){
                transplant(nodoDaEliminare, nodoDaEliminare->getLeft());
            } else {
                Node<T>* minimum = getMin(nodoDaEliminare->getRight());
                if(minimum->getParent()->getValue() != nodoDaEliminare->getValue()){
                    transplant(minimum, minimum->getRight());
                    minimum->setRight(nodoDaEliminare->getRight());
                    minimum->getRight()->setParent(minimum);
                }

                transplant(nodoDaEliminare, minimum);
                minimum->setLeft(nodoDaEliminare->getLeft());
                minimum->getLeft()->setParent(minimum);

            }
            delete nodoDaEliminare;

        }

        void preOrder(Node<T>* node, std::vector<T>& v) {
            if(node) {
                v.push_back(node->getValue());
                preOrder(node->getLeft(), v);
                preOrder(node->getRight(), v);
            }
        }

        void postOrder(Node<T>* node, std::vector<T> &v) {
            if(node) {
                postOrder(node->getLeft(), v);
                postOrder(node->getRight(), v);
                v.push_back(node->getValue());
            }
        }

        void inOrder(Node<T>* node, std::vector<T> &v) {
            if(node) {
                inOrder(node->getLeft(), v);
                v.push_back(node->getValue());
                inOrder(node->getRight(), v);
            }
        }
        Node<T>* getPredecessore(Node<T>* nodo) {
            if(nodo->getLeft() != nullptr) {
                return getMax(nodo->getLeft());
            } 
            Node<T>* parentNode = nodo->getParent();
            while(parentNode != nullptr && nodo==parentNode->getLeft()) {
                nodo = parentNode;
                parentNode = parentNode->getParent();
            }
            return parentNode;
            
        }

        Node<T>* getSuccessor(Node<T>* nodo) {
            if(nodo->getRight() != nullptr) {
                return getMin(nodo->getRight());
            }
            Node<T>* parentNode = nodo->getParent();
            while(parentNode != nullptr && nodo==parentNode->getRight()) {
                nodo = parentNode;
                parentNode = parentNode->getParent();
            }
            return parentNode;
        }

        int getHeight(Node<T>* node) {
            if(node == nullptr) {
                return 0;
            }
            return 1 + std::max(getHeight(node->getLeft()), getHeight(node->getRight()));
        }
        Node<T>* getRoot() {
            return root;
        }
        void setRoot(Node<T>* r) {
            root = r;
        }
        ~ABR() {
            
        }
};

#endif