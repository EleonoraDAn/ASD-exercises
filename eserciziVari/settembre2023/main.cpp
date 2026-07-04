#include "Settembre2023.h"

int main() {
ifstream in("../input.txt");
if(!in.is_open()) {
    cout << "Errore nel file input\n";
    return -1;
}
int numEl;
in >> numEl;
hashTable h1(numEl);
for(int i = 0; i < numEl; i++) {
    int val;
    char c;
    in >> c >> val;
    Item* it = new Item(c, val);
    h1.hashInsert(it);
}
in.close();
ofstream ot("../output.txt");
if(!ot.is_open()) {
    cout << "Errore nel file output\n";
    return -1;
}
h1.print(ot);
ot.close();
cout << "Creato il file output\n";
return 0;}
