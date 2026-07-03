#ifndef ALBERIREDBLACK_HPP
#define ALBERIREDBLACK_HPP

//codice fatto da Eleonora D'Aniello

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

const int RED = 0;
const int BLACK = 1;
class Node {
public:
    int color;
    int value;
    Node* p;
    Node* r;
    Node* l;

    Node(int v) {
    value = v;
    color = RED;
    l = r = p = nullptr;
    }
};

class AlberoRB {
private:
    int ottieniColore(Node* n) {
        if (n == nullptr) return BLACK; // Le foglie NIL sono sempre NERE
        return n->color;
    }
public:
    Node* root;
    AlberoRB() {
    root = nullptr;
    }
    void ABRInsert(Node* nodoDaInserire) {
    Node* current = root;
    Node* parent = nullptr;

    while(current!=nullptr) {
        parent = current;
        if(nodoDaInserire->value < current->value) {
            current = current->l;
        } else {
            current = current->r;
        }
    }
    nodoDaInserire->p = parent;
    if(nodoDaInserire->p == nullptr) {
        root = nodoDaInserire;
    } else if (nodoDaInserire->value < nodoDaInserire->p->value) {
        nodoDaInserire->p->l = nodoDaInserire;
    } else {
        nodoDaInserire->p->r = nodoDaInserire;
    }
    }
    void RBInsert(Node* x) {
        ABRInsert(x);

        // Ciclo di bilanciamento: finché non siamo alla radice e il padre è ROSSO
        while(x != root && x->p->color == RED) {
            if(x->p == x->p->p->l) {
                Node* z = x->p->p->r; // Zio destro

                if(ottieniColore(z) == RED) {
                    // CASO 1: lo zio è rosso -> ricolora padre, zio e nonno
                    x->p->color = BLACK;
                    z->color = BLACK;
                    x->p->p->color = RED;
                    x = x->p->p;
                } else {
                    // CASO 2: lo zio è nero e x è figlio destro (Zig-Zag)
                    if(x == x->p->r) {
                        x = x->p;
                        leftRotate(x);
                    }
                    // CASO 3: lo zio è nero e x è figlio sinistro (Linea retta)
                    x->p->color = BLACK;
                    x->p->p->color = RED;
                    rightRotate(x->p->p);
                }
            } else {
                Node* z = x->p->p->l; // Zio sinistro (caso speculare)

                if(ottieniColore(z) == RED) {
                    // CASO 1 speculare
                    x->p->color = BLACK;
                    z->color = BLACK;
                    x->p->p->color = RED;
                    x = x->p->p;
                } else {
                    // CASO 2 speculare
                    if(x == x->p->l) {
                        x = x->p;
                        rightRotate(x);
                    }
                    // CASO 3 speculare
                    x->p->color = BLACK;
                    x->p->p->color = RED;
                    leftRotate(x->p->p);
                }
            }
        }
        root->color = BLACK; // La proprietà 2 degli RB-Tree impone la radice NERA
    }

    void leftRotate(Node* x) {
    Node* y = x->r;
    x->r = y->l;
    if(y->l != nullptr) {
        y->l->p = x;
    }
    y->p = x->p;
    if(x->p == nullptr) {
        root = y;
    } else if(x == x->p->l) {
        x->p->l = y;
    }else {
        x->p->r = y;}
    y->l = x;
    x->p = y;
    }
    void rightRotate(Node* x) {
    Node* y = x->l;
    x->l = y->r;
    if(y->r != nullptr) {
        y->r->p = x;
    }
    y->p = x->p;
    if(x->p == nullptr) {
        root = y;
    } else if(x == x->p->l) {
        x->p->l = y;
    } else {
        x->p->r = y;
    }
    y->r = x;
    x->p = y;
    }

    void visitaInOrder(Node* x) {
        if(x != nullptr) {
            visitaInOrder(x->l);

            cout << "Value: " << x->value;
            cout << ", left: " << (x->l ? to_string(x->l->value) : "NIL");
            cout << ", right: " << (x->r ? to_string(x->r->value) : "NIL");
            cout << ", color: " << (x->color == RED ? "RED" : "BLACK") << "\n";

            visitaInOrder(x->r);
        }
    }

    int getBlackHeight() {
    int h = 0; // la radice non viene conssiderata nel calcolo
    Node* current = root;
    while(current!=nullptr) {
        if(current->color == BLACK)
            h = h + 1;
        current = current->l;
    }
    return h + 1; // conto anche le foglie che sono nere
    }
};
#endif // ALBERIREDBLACK__HPP
