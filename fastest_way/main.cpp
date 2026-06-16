#include <iostream>
#include <vector>
#include "CatenaMontaggio.hpp"

int main() {
    // 1. Definiamo i tempi di elaborazione (Matrice 2 x 4)
    // Riga 0: Linea 1 -> stazioni: 4, 5, 3, 2
    // Riga 1: Linea 2 -> stazioni: 2, 10, 1, 4
    std::vector<std::vector<int>> elab = {
        {4, 5, 3, 2},
        {2, 10, 1, 4}
    };

    // 2. Definiems i tempi di trasferimento (Matrice 2 x 3)
    // Riga 0: da Linea 1 (stazione j) a Linea 2 (stazione j+1) -> 2, 1, 3
    // Riga 1: da Linea 2 (stazione j) a Linea 1 (stazione j+1) -> 3, 2, 1
    std::vector<std::vector<int>> trasf = {
        {2, 1, 3},
        {3, 2, 1}
    };

    // 3. Tempi di ingresso (avvio) e di uscita (fermo) per ciascuna linea
    int avvio1 = 2, avvio2 = 4;
    int fermo1 = 1, fermo2 = 2;

    // 4. Inizializziamo l'UNICA catena di montaggio globale
    CatenaMontaggio catena(elab, trasf, avvio1, avvio2, fermo1, fermo2);

    // 5. Prepariamo la matrice L per salvare il percorso (2 righe x n stazioni)
    int n = elab[0].size();
    std::vector<std::vector<int>> L(2, std::vector<int>(n, 0));

    // 6. Calcoliamo il percorso più veloce
    int fStar = catena.percorsoPiuVeloce(L);

    // 7. Output del risultato globale
    std::cout << "Il percorso piu' veloce richiede " << fStar << " unita di tempo.\n\n";

    // 8. Ricostruzione del percorso ottimale a ritroso (Backtracking)
    // L[0][0] contiene l'ultima linea toccata prima dell'uscita
    int linea_corrente = L[0][0]; 
    
    std::cout << "Percorso ottimale (dall'ultima stazione alla prima):\n";
    for (int j = n - 1; j >= 0; j--) {
        std::cout << "Stazione " << j + 1 << " sulla Linea " << linea_corrente << "\n";
        
        // Se non siamo alla prima stazione, guardiamo da dove siamo venuti
        if (j > 0) {
            linea_corrente = L[linea_corrente - 1][j];
        }
    }

    return 0;
}