#include "cicloHamiltoniano.hpp"

int main() {
ifstream input("../input.txt");
if(!input.is_open()) {
    cout << "Errore nell'apertura del file\n";
    return -1;
}
Graph g;
int numNodes;
input >> numNodes;
for(int i = 0; i < numNodes; i++) {
    int val;
    input >> val;
    g.aggiungiNodo(val);
}
int numEdges;
bool orientato = true;
input >> numEdges;
for(int i = 0; i < numEdges; i++) {
    int destVal, sorVal;
    input >> sorVal >> destVal;
    g.aggiungiArco(sorVal, destVal, orientato);
}
input.close();
Node* start = g.nodes[0];
ofstream output("../output.txt");
if(!output.is_open()) {
    cout << "Errore nel file output\n";
    return -1;
}
if(g.cicloHam(start) == true) {
    output << "Il ciclo hamiltoniano e' presente\n";
} else {
    output << "Il ciclo hamiltoniano non e' presente\n";
}
output.close();
cout << "Creato il file output\n";
return 0;
}