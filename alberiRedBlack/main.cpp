#include "AlberiRedBlack.hpp"
int main() {
ifstream input("../input.txt");
if(!input.is_open()) {
    cout << "Errore nel file di input\n";
    return -1;
}
int numNodes;
AlberoRB A1;
input >> numNodes;
for(int i = 0; i < numNodes; i++) {
    int val;
    input >> val;
    Node* node = new Node(val);
    A1.RBInsert(node);
}

input.close();
A1.visitaInOrder(A1.root);
cout << "L'altezza nera e': " << A1.getBlackHeight() << endl;
return 0;}
