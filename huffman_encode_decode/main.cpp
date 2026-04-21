#include "Huffman.hpp"
int main() {
    std::ifstream inputFile("../stringa.txt");
    if(!inputFile.is_open()) {
        std::cout << "Errore nell'apertura del file di input\n";
        return 1;
    }
    std::string data;
    inputFile >> data;

    HuffmanTree firstTree(data);

    std::string encoded = firstTree.encode(data);
    std::string decoded = firstTree.decode(encoded);

    inputFile.close();


    std::ofstream outputFile("../outputString.txt");
    if(!outputFile.is_open()) {
        std::cout << "Errore nell'apertura del file di output!\n";
        return 1;
    }
    outputFile << "Stringa codificata: " << encoded << "\n";
    outputFile << "Stringa decodificata: " << decoded << "\n";

    outputFile.close();

    std::cout << "Creato il file di output\n";
    firstTree.getCodes();
    return 0;
}