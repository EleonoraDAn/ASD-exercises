#ifndef LUGLIO2023_H
#define LUGLIO2023_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>
#include <fstream>
using namespace std;
/*
Costruire abr con coppia chiave carattere da file, dove era salvato secondo
l'ordine preorder, poi metodo per stampare su file di output l'albero secondo il
preorder

codifica e decodifica di human considerando l'abr dato come
albero di human*/

class Node {
public:
    Node* p;
    Node* r;
    Node* l;
    pair<char, int> coppia;
    Node(char c, int n) {
    l = p = r = nullptr;
    coppia.first = c;
    coppia.second = n;
    }

};
class Compare{
public:
    bool operator()(Node* l, Node* r) {
    return l->coppia.second > r->coppia.second;}
};
class ABR{
public:
    Node* root;
    ABR() : root(nullptr) {}
    vector<Node*> abr;
    unordered_map<char, string> codes;
    void ABRToHuffman() {
    unordered_map<char, int> freq;
    for(Node* n : abr){
        freq[n->coppia.first] ++;
    }

    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto coppia : freq) {
            Node* nuovoFoglia = new Node(coppia.first, coppia.second);
            pq.push(nuovoFoglia);
    }
    while(pq.size() > 1) {
        Node* l = pq.top();
        pq.pop();
        Node* r = pq.top();
        pq.pop();
        Node* z = new Node('$', l->coppia.second + r->coppia.second);
        z->l = l;
        z->r = r;
        pq.push(z);
    }
    root = pq.top();
    pq.pop();
    generateCode(root, "");
    }

    void insertABR(char c, int n) {
    Node* nodoDaInserire = new Node(c, n);
    Node* current = root;
    Node* parent = nullptr;
    while(current!=nullptr) {
        parent = current;
        if(nodoDaInserire->coppia.second < current->coppia.second) {
            current = current->l;
        } else {
            current = current->r;
        }
    }
    nodoDaInserire->p = parent;
    if(nodoDaInserire->p == nullptr) {
        root = nodoDaInserire;
    } else if(nodoDaInserire->coppia.second < nodoDaInserire->p->coppia.second) {
        nodoDaInserire->p->l = nodoDaInserire;
    } else {
        nodoDaInserire->p->r = nodoDaInserire;
    }
    abr.push_back(nodoDaInserire);
    }

    void visitaPreOrder(Node* x, vector<Node*>&A) {
    if(x!=nullptr) {
        A.push_back(x);
        visitaPreOrder(x->l, A);
        visitaPreOrder(x->r, A);
    }
    }

    void generateCode(Node* x, string d) {
        if(x->l == nullptr && x->r == nullptr) {
            codes[x->coppia.first] = d;
            return;
        }
        generateCode(x->l, d+"0");
        generateCode(x->r, d+"1");
    }

    string encode(string data) {
    string encoded = "";
    for(char c : data) {
        encoded += codes[c];
    }
    return encoded;
    }

    string decode(string data) {
    string decoded = "";
    Node* current = root;
    for(char c : data) {
        if(c == '0') {
            current = current->l;
        } else {
            current = current->r;
        }

    if(current->l == nullptr && current->r == nullptr) {
        decoded += current->coppia.first;
        current = root;
    }
    }
    return decoded;
    }
};

#endif // LUGLIO2023_H
