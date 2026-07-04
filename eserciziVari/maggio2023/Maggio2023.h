#ifndef MAGGIO2023_H
#define MAGGIO2023_H

#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <limits.h>
#include <string>
#include <map>
using namespace std;
/*
.Usando il paradiĀma della proĀrammazione ad oĀĀetti ed linĀuaĀĀio C++ 11
proĀettare ed implementare una classe graph che consenta di caricare dati di un
Āraÿo non orientato pesato G contenuti nel file GRP.txt II file testo contiene nel
primo riĀo due interi separati da uno spazio che indicano, rispettivamente, il
numero di nodi ed il numero di archi.
I successivi riĀhi contenĀono ciascuno tre numeri, separati da uno spazio, per
indicare il nodo sorĀente, nodo destinazione ed il peso di oĀni arco. Dotare la
classe di un metodo BFS(s) che scrive nel file OUT.txt, per oĀni nodo, la distanza
dal nodo s ed il proprio predecessore. (pt. 18)*/
const int INF = INT_MAX;
const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;
class Node {
public:
    int value;
    int color;
    int d;
    Node* p;
    Node(int value) {
    this->value = value;
    color = WHITE;
    d = INF;
    }

};
/*.Dotare la classe dei metodi PRIM() e PRINT_MST() per calcolare e stampare a video
il minimum spanning tree. (pt. 6)
*/
class Graph{
public:
    int V;
    vector<int> key;
    vector<int> parent;
    vector<vector<pair<int, int>>> adj;

    vector<Node*> nodes;
    map<int, Node*> raggiungiNodo;
    map<int, vector<pair<int, int>>> adjBFS;

    Graph(int V) {
    this->V = V;
    adj.resize(V);
    }

    void aggiungiNodo(int val) {
        Node* nodo = new Node(val);
        nodes.push_back(nodo);
        raggiungiNodo[val] = nodo;
    }

    void aggiungiArcoBFS(int a, int b, int peso) {
    Node* u = raggiungiNodo[a];
    Node* v = raggiungiNodo[b];
    adj[u->value].push_back(make_pair(v->value, peso));
    adj[v->value].push_back(make_pair(u->value, peso));
    }
    void aggiungiArco(int u, int v, int peso) {
    adj[u].push_back(make_pair(v, peso));
    adj[v].push_back(make_pair(u, peso));
    }
    // NB: NELL'INPUT.TXT DOBBIAMO INSERIRE VALORI CHE VANNO DA 0 A numNodes-1 se no va in seg. fault
    void prim() {
        vector<bool> inMst(V, false);
        parent.assign(V, -1);
        key.assign(V, INT_MAX);
        int src = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        key[src] = 0;
        pq.push(make_pair(0, src));
        while(!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            if(inMst[u] == true) continue;
            inMst[u] = true;
            for(auto i = adj[u].begin(); i!=adj[u].end(); i++) {
                int v = i->first;
                int p = i->second;
                if(inMst[v] == false && p < key[v]) {
                    key[v] = p;
                    pq.push(make_pair(key[v], v));
                    parent[v] = u;
                }
            }
        }
    }

    void printMst() {
    int peso_tot = 0;
    cout << "Minimum spanning tree\n";
    for(int i = 1; i < V; ++i) {
        if(parent[i] != -1 && key[i] != INT_MAX) {
            cout << "[" << i << "] = ";
            cout << "<" << parent[i]<< ">\n";
            peso_tot += key[i];
        }
    }
    cout << "Il costo totale e' uguale a: " << peso_tot << "\n";
    }

    /*.Dotare la classe del metodo IS_BINARY(MST) che restituisca TRUE se MST è un
    albero binario e FALSE altrimenti. (pt. 6)*/

    // un albero binario deve avere al max 2 figli.
    bool isMst() {
    vector<int> cont(V, 0);
    for(int i = 0; i < V; i++){
        int padre = parent[i];
        if(padre != -1) {
            if(padre >=0 && padre < V) {
                cont[padre] ++;
            }
        }
    }

    for(int i = 0; i < V; i++){
        if(cont[i] > 2)
            return false;
    }
    return true;
    }

    void bfs(Node* s) {
    for(Node* n : nodes) {
        if(n != s) {
            n->d = INF;
            n->color = WHITE;
            n->p = nullptr;
        }
    }
    s->color = GRAY;
    s->d = 0;
    s->p = nullptr;
    queue<Node*> q;
    q.push(s);
    while(!q.empty()) {
        Node* u = q.front();
        q.pop();
        for(auto n : adj[u->value]) {
            Node* a = raggiungiNodo[n.first];
            if(a->color == WHITE) {
                a->color = GRAY;
                a->d = u->d + 1;
                a->p = u;
                q.push(a);
            }
        }
        u->color = BLACK;
    }

    }
};
#endif // MAGGIO2023_H
