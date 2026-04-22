#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <algorithm>
#include <stack>
#include <map>
#include <queue>
#include <string>

class Node {
    public:
        int key, value, rank, id, dist;
        Node* parent;
        Node(int id, int value) : value(value), id(id), dist(std::numeric_limits<int>::max()) {}
};

class Edge {
    public:
        int weight;
        Node* source;
        Node* destination;
        Edge(int weight, Node* source, Node* destination) : weight(weight), source(source), destination(destination) {}
};

struct CompareNode {
    bool operator()(const Node* a, const Node* b) const {
        return a->key > b->key;
    }
};

class Graph{
    public:
        std::vector<Node*> nodes;
        std::vector<Edge*> edges;
        std::vector<int> parent;
        std::vector<int> distance;
        std::map<int, std::vector<std::pair<int, int>>> adjList;
        
        Graph(int n) {
            parent.resize(n);
            for(int i = 0; i<n; i++) {
                parent[i] = i;
            }
            distance.resize(n, std::numeric_limits<int>::max());
        }

        void addNode(Node* node) {
            nodes.push_back(node);
        }

        void addEdge(Edge* edge) {
            edges.push_back(edge);
            adjList[edge->source->id].push_back({edge->destination->id, edge->weight});
        }

        void initializeSingleSource(Node* source) {
            for(auto n : nodes) {
                n->dist = std::numeric_limits<int>::max();
            }
            source->dist = 0;
            distance[source->id] = 0;
        }

        void relax(Edge* edge) {
            int newDist = edge->source->dist + edge->weight;
            if(newDist < edge->destination->dist) {
                edge->destination->dist = newDist;
                distance[edge->destination->id] = newDist;
                parent[edge->destination->id] = edge->source->id;
            }
        }

        void dijkstra(Node* source) {
            initializeSingleSource(source);
            std::priority_queue<std::pair<int, Node*>, std::vector<std::pair<int, Node*>>, std::greater<std::pair<int, Node*>>> pq;
            pq.push({source->dist, source});
            while(!pq.empty()) {
                Node* curr = pq.top().second;
                pq.pop();
                for(auto edge : edges) {
                    if(edge->source == curr) {
                        relax(edge);
                        pq.push({edge->destination->dist, edge->destination});
                    }
                }
            }
        }

        std::string bellmanFord(Node* source) {
            initializeSingleSource(source);
            int i = 0;
            while (i<nodes.size()){
                for(auto edge : edges) {
                    relax(edge);
                }

                for(auto edge : edges) {
                    if(edge->destination->dist > edge->source->dist + edge->weight) {
                        return "Trovato ciclo negativo!\n";
                    }
                }
                i++;
            }

            return "Nessun ciclo negativo trovato!\n";
        }

        Node* findSet(Node* x) {
            if(x != x->parent) {
                x->parent = findSet(x->parent);
            }
            return x->parent;
        }

        void link(Node* x, Node* y) {
            if(x->rank > y->rank) {
                y->parent = x;
            } else {
                x->parent = y;
            }

            if(x->rank == y->rank) {
                y->rank++;
            }
        }

        void makeSet(Node* x) {
            x->parent = x;
            x->rank = 0;
        }

        void unionSet(Node* x, Node* y) {
            link(findSet(x), findSet(y));
        }

        std::vector<Edge*> kruskal() {
            std::vector<Edge*> A;
            for(auto node:nodes) {
                makeSet(node);
            }

            std::sort(edges.begin(), edges.end(), [](Edge* a, Edge* b){
                return a->weight < b->weight;
            });

            for(auto edge : edges) {
                if(findSet(edge->source) != findSet(edge->destination)) {
                    A.push_back(edge);
                    unionSet(edge->source, edge->destination);
                }
            }

            return A;
        }

        void showAdjList(Node* u) {
            std::cout << "Lista di adiacenza del nodo " << u->id << ":\n";
            for(auto it = adjList[u->id].begin(); it!=adjList[u->id].end(); it++) {
                std::cout << " " << u->id << " ->" << it->first << " (peso " << it->second << ")\n";
            }
        }

};
#endif