#ifndef ORDINAMENTOTOPOLOGICO_HPP
#define ORDINAMENTOTOPOLOGICO_HPP

#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <fstream>
using namespace std;

// per costruire l'ordinamento topologico, dobbiamo avere un DAG (Directed acyclic graph)
const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;
const int INF = 99999;
class Node {
public:
    Node* p;
    int color;
    int value;
    int d;
    int f;

    Node(int v) {
    p = nullptr;
    color = WHITE;
    value = v;
    }
};

class Graph {
public:
    vector<Node*> nodes;
    map<int, vector<int>> adj;
    stack<Node*> ordinTop;
    int time = 0;
    void aggiungiNodo(int val) {
    Node* nodo = new Node(val);
    nodes.push_back(nodo);
    }

    void aggiungiArco(int a, int b) {
    adj[a].push_back(b);
    }

    bool ordinamentoTop() {
    for(Node* n : nodes) {
        n->color = WHITE;
        n->p = nullptr;
    }
    while(!ordinTop.empty()) ordinTop.pop();
    for(Node* n : nodes) {
        if(n->color ==  WHITE) {
            if(dfs_r(n) == false) {
                while(!ordinTop.empty()) ordinTop.pop();
                return false;
            }
        }
    }
    return true;
    }


    bool dfs_r(Node* u) {
        time ++;
        u->d = time;
        u->color = GRAY;
        for(auto v : adj[u->value]) {
            Node* node = nullptr;
            for(Node* n : nodes) {
                if(n->value == v) {
                    node = n;
                    break;
                }
            }
            if(node == nullptr)
                continue;
            if(node->color == GRAY)
                return false;
            else if(node->color == WHITE) {
                node->p = u;
                if(dfs_r(node)==false)
                    return false;
            }
        }
        time ++;
        u->f = time;
        u->color = BLACK;
        ordinTop.push(u);
        return true;
    }

};
#endif // ORDINAMENTOTOPOLOGICO_HPP
