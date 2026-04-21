#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <functional>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <string>
const int WHITE = 0;
const int GREY = 1;
const int BLACK = 2;
const int INFINITY = 9999;

template<typename T>
class Node {
    public:
        T value, key;
        T distance = INFINITY;
        int color = WHITE;
        int rank;
        T discovery_time = 0;
        T finish_time = 0;
        Node<T>* parent;
        std::string percorso;
        Node(T v) : value(v) {}
};

template<typename T>
class Edge {
    public:
        T weight;
        Node<T>* source;
        Node<T>* destination;
        Edge(T weight, Node<T>* source, Node<T>* destination):weight(weight), source(source), destination(destination) {}
};

template<typename T>
class minCompare {
    public: 
        bool operator()(Node<T>* a, Node<T>* b) {
            return a->key > b->key;
        }
};

template<typename T>
class Graph {
    public:
        T time = 0;
        std::vector<Node<T>*> nodes;
        std::vector<Edge<T>*> edges;
        std::map<T, std::vector<std::pair<T, T>>> adjacencyList;

        // AGGIUNGI NODO
        void addNode(Node<T>* node) {
            nodes.push_back(node);
        }

        // AGGIUNGI L'ARCO(source, destination) E L'ARCO(destination, source)
        void addEdge(Node<T>* source, Node<T>* destination, T weight) {
            Edge<T>* edge = new Edge<T>(weight, source, destination);
            edges.push_back(edge);
            adjacencyList[source->value].push_back(std::make_pair(destination->value, weight));
            adjacencyList[destination->value].push_back(std::make_pair(source->value, weight));
        }

        // BFS
        void bfs(Node<T>* startNode) {
            
            for(Node<T>* n:nodes) {
                n->color = WHITE;
                n->distance = INFINITY;
                n->parent = nullptr;
            }
            startNode->color = GREY;
            startNode->distance = 0;
            startNode->parent = nullptr;
            startNode->percorso = std::to_string(startNode->value);
            std::queue<Node<T>*> q;
            q.push(startNode);

            while(!q.empty()) {
                Node<T>* u = q.front();
                q.pop();
                for(auto v : adjacencyList[u->value]) {
                    Node<T>* node = nullptr;
                    for(Node<T>* n : nodes) {
                        if(n->value == v.first) {
                            node = n;
                            break;
                        }
                    }

                    if(node == nullptr) {
                        continue;
                    }

                    if(node->color == WHITE) {
                        node->color = GREY;
                        node->distance = u->distance + v.second;
                        node->parent = u;
                        node->percorso = u->percorso + "->" + std::to_string(node->value);
                        q.push(node);
                    }
                }

                u->color = BLACK;
            }
        }

        void dfs() {
            for(auto u:nodes) {
                u->color = WHITE;
                u->parent = nullptr;
            }
            for(auto u:nodes) {
                if(u->color == WHITE) {
                    dfsVisit(u);
                }
            }
        }

        void dfsVisit(Node<T>* u) {
            u->color = GREY;
            u->discovery_time = ++time;
            for(auto v : adjacencyList[u->value]) {
                Node<T>* node = nullptr;
                for(Node<T>* n:nodes) {
                    if(n->value == v.first) {
                        node = n; 
                        break;
                    }
                }

                if(node == nullptr) {
                    continue;
                }

                if(node->color == WHITE) {
                    node->parent = u;
                    dfsVisit(node);
                }
            }
            u->color = BLACK;
            u->finish_time = ++time;
        }

        void unionSet(Node<T>* x, Node<T>* y) {
            linkSet(findSet(x), findSet(y));
        }

        void linkSet(Node<T>* x, Node<T>* y) {
            if(x->rank > y->rank) {
                y->parent = x;
            } else {
                x->parent = y;
            }
            if(x->rank == y->rank) {
                y->rank++;
            }
        }

        Node<T>* findSet(Node<T>* x) {
            if(x != x->parent) {
                x->parent = findSet(x->parent);
            }
            return x->parent;
        }

        void makeSet(Node<T>* x) {
            x->parent = x;
            x->rank = 0;
        }

        void connectedComponents() {
            for(auto v:nodes) {
                makeSet(v);
            }
            for(auto e:edges) {
                if(findSet(e->source) != findSet(e->destination)) {
                    unionSet(e->source, e->destination);
                }
            }
        }
};

#endif