#include "OrdinamentoTopologico.hpp"

int main() {
ifstream input("../input.txt");
if(!input.is_open()) {
    cout << "Errore nel file input\n";
    return -1;
}
int numNodes;
input >> numNodes;
Graph g;
for(int i = 0; i < numNodes; i++) {
    int val;
    input >> val;
    g.aggiungiNodo(val);
}
int numEdges;
input >> numEdges;
for(int i = 0; i < numEdges; i++) {
    int sV, dV;
    input >> sV >> dV;
    g.aggiungiArco(sV, dV);
}
input.close();
ofstream output("../output.txt");
if(!output.is_open()) {
    cout << "Errore nel file output\n";
    return -1;
}
if(g.ordinamentoTop()) {
    while(!g.ordinTop.empty()) {
        Node* n = g.ordinTop.top();
        g.ordinTop.pop();
        output << "Value: " << n->value << ", u->d: " << n->d << ", u->f: " << n->f << "\n";
    }
} else {
    output << "C'e' un ciclo! Non e' un dag!\n";
}
output.close();
cout << "Creato il file output\n";
return 0;}