#include "EditingDistance.hpp"
int main() {
    std::ifstream fileInput("../input.txt");
    if(!fileInput.is_open()) {
        std::cout << "Errore nell'apertura del file input!\n";
        return -1;
    }
    int numNomi;
    fileInput >> numNomi;
    std::vector<std::string> nomi;
    for(int i = 0; i < numNomi; i++) {
        std::string nome;
        fileInput >> nome;
        nomi.push_back(nome);
    }

    fileInput.close();

    
    std::ofstream fileOutput("../output.txt");
    if(!fileOutput.is_open()) {
        std::cout << "Errore nell'apertura del file output!\n";
        return -1;
    }

    Tree albero(nomi);
    std::string parola;
    int k;
    std::cout << "Inserisci una parola da ricercare\n";
    std::cin >> parola;
    std::cout << "Inserisci la distanza massima che questa parola deve avere da un'altra\n";
    std::cin >> k;
    std::vector<std::string> result = albero.findWords(parola, k);
    if(result.empty()) {
        fileOutput << "Non ci sono risultati.\n";
    } else {
        fileOutput << "Le parole che hanno distanza " << k << " da " << parola << " sono:\n";
        for(std::string p : result) {
            fileOutput << p;
            if(p != result[result.size()-1]) fileOutput << ",\n";
        }
    }
    fileOutput.close();
    std::cout << "Creato il file output\n";

    /* DAGLI INPUT DISPONIBILI SI EVINCE CHE:
    Se si inserisce "salone" e k = 2 non ci sono risultati.
    Se abbiamo "salone" e k=3 allora l'unica parola visualizzata è "salotto" perchè:
    1. "salo" rimane uguale
    2. la prima t in "salotto" viene sostituita con n
    3. la seconda t viene sostituita con e
    4. eliminiamo la o finale.
    In totale avremo 3 operazioni. */
    return 0;
}