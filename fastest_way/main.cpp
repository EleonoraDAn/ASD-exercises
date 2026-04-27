#include "CatenaMontaggio.hpp"
int main() {
    std::vector<int> elab1 = {4, 5, 3, 2};
    std::vector<int> trasf1 = {2, 1, 3};
    int avvio1 = 2, fermo1 = 1;
    CatenaMontaggio catena1(elab1, trasf1, avvio1, fermo1);

    std::vector<int> elab2 = {2, 10, 1, 4};
    std::vector<int> trasf2 = {3, 2, 1};
    int avvio2 = 4, fermo2 = 2;
    CatenaMontaggio catena2(elab2, trasf2, avvio2, fermo2);

    int e1 = elab1[0], e2 = elab2[0];
    int x1 = fermo1, x2 = fermo2;
    std::vector<int> L1(elab1.size()), L2(elab2.size());
    int fStar = std::min(catena1.percorsoPiuVeloce(e1, e2, x1, x2, L1), catena2.percorsoPiuVeloce(e2, e1, x2, x1, L2));

    std::cout << "Il percorso piu' veloce richiede " << fStar << " unita di tempo.\n";
    std::cout << "Sequenza di svolgimento delle attivita' sulla prima catena: ";
    for(unsigned int i = 0; i < L1.size(); i++) {
        if(i>0) {
            if(L1[i] != L1[i-1]) {
                std::cout << " | ";
            }
        }
        std::cout << "L" << L1[i] << " ";
    }

    std::cout << std::endl;
    std::cout << "Sequenza di svolgimento delle attivita' sulla seconda catena: ";
    for(unsigned int i = 0; i<L2.size(); i++) {
        if(i > 0) {
            if(L2[i] != L2[i-1]) {
                std::cout << " | ";
            }
        }
        std::cout << "L" << L2[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}