#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <queue>
#include <iostream>
#include <fstream>

const int WHITE = 0;
const int GREY = 1;
const int BLACK = 2;
const int INF = 999999;

template<typename T>
class Node {
    public:
        T value;
        int color = WHITE;
        int id;
        T dist;
        Node<T>* parent;
        std::vector<Node<T>*> adj;

        Node(int id, T value) : value(value), id(id) {}
};

template<typename T>
class Edge {
    public:
        Node<T>* source;
        Node<T>* destination;

        Edge(Node<T>* source, Node<T>* destination) : source(source), destination(destination) {}
};

template<typename T>
class Graph {
    public:
        std::vector<Node<T>*> nodes;
        std::vector<Edge<T>*> edges;

        Graph() {}

        void addNode(Node<T>* node) {
            nodes.push_back(node);
        }

        void addEdge(Node<T>* source, Node<T>* destination) {
            Edge<T>* edge = new Edge(source, destination);
            edges.push_back(edge);
            source->adj.push_back(destination);
        }

        void BFS(Node<T>* s) {
            for(auto u : nodes) {
                if(u != s) {
                    u->color = WHITE;
                    u->dist = INF;
                    u->parent = nullptr;
                }
            }
            s->dist = 0;
            s->color = WHITE;
            s->parent = nullptr;
            std::queue<Node<T>*> Q;
            Q.push(s);
            while(!Q.empty()) {
                Node<T>* u = Q.front();
                Q.pop();
                for(auto v : u->adj) {
                    if(v->color == WHITE) {
                        v->color = GREY;
                        v->dist = u->dist + 1;
                        v->parent = u;
                        Q.push(v);
                    }
                }
                u->color = BLACK;
            }
        }

        void BfsRicorsiva(Node<T>* u) {
            u->color = GREY;
            for(auto v : u->adj) {
                if(v->color == WHITE) {
                    v->parent = u;
                    v->dist = u->dist + 1;
                    BfsRicorsiva(v);
                }
            }
            u->color = BLACK;
        }

};
#endif