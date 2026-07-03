#ifndef CICLOHAMILTONIANO_HPP
#define CICLOHAMILTONIANO_HPP
#include <iostream>
#include <vector>
#include <map>
#include <fstream>

const int WHITE = 0;
const int GRAY = 1;

using namespace std;
class Node {
public:
    int color;
    int value;
    Node* p;
    Node(int v) {
    p = nullptr;
    value = v;
    color = WHITE;
    }
};

class Graph{
public:
    vector<Node*> nodes;
    map<int, vector<int>> adj;

    void aggiungiNodo(int v) {
    Node* nodo = new Node(v);
    nodes.push_back(nodo);
    }

    void aggiungiArco(int a, int b, bool orientato = true) {
    adj[a].push_back(b);
    if(!orientato) {
        adj[b].push_back(a);}
    }

    bool cicloHam(Node* start) {
    int tot = nodes.size();
    for(Node* n : nodes) {
        n->color = WHITE;
    }
    return DFS_R(start, start, 1, tot);
    }

private:
    bool DFS_R(Node* u, Node* s, int c, int t) {
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

        if(node == s && c == t)
            return true;
        if(node->color == WHITE) {
            if(DFS_R(node, s, c + 1, t))
                return true;
        }
    }
    u->color = WHITE;
    return false;
    }
};
#endif // CICLOHAMILTONIANO_HPP
