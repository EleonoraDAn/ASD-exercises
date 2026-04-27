#ifndef GREEDYACTIVITYSELECTOR_HPP
#define GREEDYACTIVITYSELECTOR_HPP

#include <map>
#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <string>

std::ifstream creazioneInput(std::string nomeFile) {
    std::ifstream fileInput(nomeFile);
    if(!fileInput.is_open()) {
        throw std::runtime_error("Errore nell'apertura del file input!");
    }
    return fileInput;
}

std::ofstream creazioneOutput(std::string nomeFile) {
    std::ofstream fileOutput(nomeFile);
    if(!fileOutput.is_open()) {
        throw std::runtime_error("Errore nell'apertura del file output!");
    }
    return fileOutput;
}
void GreedyActivitySelector(std::list<int> A, std::vector<int> start, std::vector<int> finish) {
    /* int n;
    std::cout << "Inserisci il numero di attivita'\n";
    std::cin >> n;
    int tempoFine, tempoInizio;
    for(int i = 0; i<n; i++) {
        std::cout << "Inserisci il tempo di inizio\n";
        std::cin >> tempoInizio;
        start.push_back(tempoInizio);
    }
    std::cout << std::endl;
    for(int x = 0; x < n; x++) {
        std::cout << "Inserisci il tempo di fine\n";
        std::cin >> tempoFine;
        finish.push_back(tempoFine);
    } */
    // CON I FILE
    std::ifstream fileInput = creazioneInput("../input.txt");
    int n;
    if(fileInput) {
        fileInput >> n;
        for(int i = 0; i<n; i++) {
            int tempoInizio, tempoFine;
            fileInput >> tempoInizio >> tempoFine;
            start.push_back(tempoInizio);
            finish.push_back(tempoFine);
        }
        
        fileInput.close();
    }
    std::ofstream fileOut = creazioneOutput("../output.txt");
    if(fileOut) {
        // std::cout << std::endl;
        A.push_back(0);
        int prev = 0;

        for(int j = 1; j < n; j++) {
            if(start[j] >= finish[prev]) {
                A.push_back(j);
                prev = j;
            }
        }
        
        std::list<int>::iterator lii;
        for(lii = A.begin(); lii != A.end(); lii++) {
            fileOut << "Attivita' schedulate: " << *lii << std::endl;
        }

        fileOut.close();
        std::cout << "Creato il file di output\n";
    }
}

#endif