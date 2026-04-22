#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <iostream>
#include <vector>
#include <queue>


class Grafo {
    private:
        int V;
        std::vector<std::vector<std::pair<int, int>>> adj;
    public:
        Grafo(int V) {
            this->V = V;
            adj.resize(V);
        }

        void aggiungiArco(int u, int v, int peso) {
            adj[u].push_back(std::make_pair(v, peso));
            adj[v].push_back(std::make_pair(u, peso));
        }

        int prim() {
            std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
            int src = 0;
            std::vector<int> parent(V, -1);
            std::vector<bool> inMst(V, false);
            std::vector<int> key(V, INT_MAX);

            pq.push(std::make_pair(0, src));
            key[src] = 0;

            while(!pq.empty()) {
                int u = pq.top().second;
                pq.pop();
                inMst[u] = true;
                for(auto i = adj[u].begin(); i != adj[u].end(); ++i) {
                    int v = i->first;
                    int peso = i->second;

                    if(inMst[v] == false && peso < key[v]) {
                        key[v] = peso;
                        pq.push(std::make_pair(key[v], v));
                        parent[v] = u;
                    }
                }
            }

            int costoTotale = 0;
            for(int i = 1; i < V; ++i) {
                std::cout << parent[i] << " - " << i << "  " << key[i] << std::endl;
                costoTotale += key[i];
            }

            return costoTotale;
        }
};

#endif