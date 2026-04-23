#include "Hashtable.hpp"
int main() {
    std::ifstream fileInput("../input.txt");
    if(!fileInput.is_open()) {
        std::cout << "Errore nell'apertura del file di input\n";
        return -1;
    }
    int hashSize;
    fileInput >> hashSize;
    Hashtable<int> hash(hashSize);
    for(int i = 0; i<hashSize; i++) {
        int key, val;
        fileInput >> key >> val;
        Item<int>* item = new Item<int>(key, val);
        hash.insert(item);
    }

    fileInput.close();
    // Item<int>* result = hash.search(10);  output: elemento non trovato
    Item<int>* result = hash.search(8);
    std::ofstream fileOut("../output.txt");
    if(!fileOut.is_open()) {
        std::cout << "Errore nell'apertura del file di output\n";
        return -1;
    }

    if(result != nullptr) {
        fileOut << "Elemento trovato!\nElemento->key: " << result->key << "\nElemento->value: " << result->value << std::endl;
    } else  {
        fileOut << "Elemento non trovato!\n";
    }
    fileOut.close();

    std::cout << "Creato il file di output\n";
    return 0;
}