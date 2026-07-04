#include "Luglio2023.h"
int main() {
ifstream input("../input.txt");
if(!input.is_open()) {
    cout << "Errore file input\n";
    return -1;
}
int numNodes;
input >> numNodes;
ABR abr;
for(int i = 0; i < numNodes; i++) {
    int v;
    char c;
    input >> c >> v;
    abr.insertABR(c, v);
}
input.close();
ofstream output("../output.txt");
if(!output.is_open()) {
    cout << "Errore file output\n";
    return -1;
}

vector<Node*> preOrderVisit;
abr.visitaPreOrder(abr.root, preOrderVisit);
for(Node* n : preOrderVisit) {
    output << "Chiave: " << n->coppia.first << ", Valore: " << n->coppia.second << "\n";
}

abr.ABRToHuffman();
string data = "CAVA";
string encoded = abr.encode(data);
output << "La stringa: " << data << " codificata e': " << encoded << "\n";
output << "La stringa decodificata e': " << abr.decode(encoded) << "\n";
output.close();
cout << "Creato il file output\n";
return 0;}