#include "Hashtable.hpp"

int main() {
    std::ifstream fileInput("../input.txt");
    if(!fileInput.is_open()) {
        std::cout << "Errore nell'apertura del file di input\n";
        return -1;
    }
    
    int hashSize;
    fileInput >> hashSize;
    
    // Inizializziamo la tabella con la capacità letta dal file 
    Hashtable<int, std::string> hash(hashSize); 
    
    for(int i = 0; i < hashSize; i++) {
        int key;
        std::string val; // CORRETTO: il valore è una stringa 
        
        fileInput >> key >> val;
        Item<int, std::string>* itemDaInserire = new Item<int, std::string>(key, val);
        // CORRETTO: Passiamo direttamente chiave e valore, 
        // lasciando che la classe gestisca l'allocazione internamente
        hash.insert(itemDaInserire); 
    }
    fileInput.close();

    // Mostriamo a video la tabella hash iniziale (comodo per l'esame)
    std::cout << "--- Contenuto iniziale della Hash Table ---\n";
    hash.print();
    std::cout << "-------------------------------------------\n\n";

    // Esempio d'uso dei metodi richiesti: SEARCH e DELETE [cite: 34, 35]
    // CORRETTO: Cerchiamo tramite una chiave INTERA (es. 10), non tramite stringa [cite: 34]
    int chiaveDaCercare = 6; 
    Item<int, std::string>* result = hash.search(chiaveDaCercare);

    std::ofstream fileOut("../output.txt");
    if(!fileOut.is_open()) {
        std::cout << "Errore nell'apertura del file di output\n";
        return -1;
    }

    if(result != nullptr) {
        fileOut << "Elemento trovato!\nElemento->key: " << result->key 
                << "\nElemento->value: " << result->value << std::endl;
    } else {
        fileOut << "Elemento con chiave " << chiaveDaCercare << " non trovato!\n";
    }
    fileOut.close();
    std::cout << "Creato il file di output\n\n";

    // Esempio facoltativo del metodo DELETE richiesto dalla traccia [cite: 35]
    // std::cout << "--- Test Cancellazione ---\n";
    // hash.remove(10); // Elimina l'elemento con chiave 10 [cite: 35]
    // hash.print();    // Mostra la tabella aggiornata [cite: 35]

    return 0;
}