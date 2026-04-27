#include "Ordinamenti.hpp"
int main() {
    std::vector<int> A;
    std::ifstream fileInput("../input.txt");
    if(!fileInput.is_open()) {
        std::cout << "Errore nell'apertura del file input\n";
        return -1;
    }
    int num;
    while(fileInput >> num) {
        A.push_back(num);
    }
    fileInput.close();

    Array myArray(A);
    myArray.mergeSort(A, 0, A.size()-1);
    // myArray.insertionSort(A);
    // myArray.bubbleSort(A);

    std::ofstream fileOut("../output.txt");
    if(!fileOut.is_open()) {
        std::cout << "Errore nell'apertura del file di output\n";
        return -1;
    }
    for(auto el : A) {
        fileOut << el << " ";
    } 
    std::cout << std::endl;
    fileOut.close();
    std::cout << "Creato il file output\n";
    return 0;
}