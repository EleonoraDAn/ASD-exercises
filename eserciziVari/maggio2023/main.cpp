#include "Maggio2023.h"

int main() {

ifstream input("../GPR.txt");
if(!input.is_open()) {
    cout << "Errore nel file input\n";
    return -1;
}
int numNodes, numArc;
input >> numNodes >> numArc;
Graph g(numNodes);
for(int i = 0; i < numNodes; i++) {
    int uVal;
    input >> uVal;
    g.aggiungiNodo(uVal);
}
for(int i = 0; i < numArc; i++) {
    int uVal, vVal, peso;
    input >> uVal >> vVal >> peso;
    g.aggiungiArco(uVal, vVal, peso);
    g.aggiungiArcoBFS(uVal, vVal, peso);
}
input.close();
g.prim();
g.printMst();
if(g.isMst())
    cout << "L'albero dei cammini minimi e' binario\n";
else
    cout << "L'albero dei cammini minimi non e' binario\n";
ofstream out("../OUT.txt");
if(!out.is_open()) {
    cout << "Errore file output\n";
    return -1;
}
g.bfs(g.nodes[0]);
for(Node* n : g.nodes) {
        out << "Value: " << n->value << ",\n parent: " << (n->p == nullptr? "NULL":to_string(n->p->value)) << ",\n dist: " << (n->d == INF?"INF":to_string(n->d)) << "\n";
    }
out.close();
cout << "Creato il file output\n";
return 0;
}
