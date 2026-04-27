#include "Lcs.hpp"
int main() {
    std::cout << "Inserisci la prima stringa\n";
    std::cin >> X;
    std::cout << "Inserisci la seconda stringa\n";
    std::cin >> Y;
    LCS();
    std::cout << "LCS lunghezza: " << c[n][m] << std::endl;
    std::cout << "LCS: ";
    printLCS(n, m);
    std::cout << std::endl;
    printB();
    return 0;
}