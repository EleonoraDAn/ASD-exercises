#include "Knapsack.hpp"
int main() {
    std::ifstream fileInput("../input.txt");
    if(!fileInput.is_open()) {
        std::cout << "Errore nell'apertura del file di input\n";
        return -1;
    }
    std::vector<Item<int>*> items;
    int capacity, numItems;
    fileInput >> capacity >> numItems;
    for(int i = 0; i < numItems; i++) {
        int value, weight;
        fileInput >> value >> weight;
        Item<int>* item = new Item<int>(value, weight);
        items.push_back(item);
    }
    Knapsack zaino(items, capacity);
    fileInput.close();
    std::vector<Item<int>> solution01 = zaino.solve01();
    std::vector<std::pair<Item<int>, double>> fractionalSolution = zaino.solveFractional();
    std::ofstream out("../output.txt");
    if(!out.is_open()) {
        std::cout << "Errore nell'apertura del file di output\n";
        return -1;
    }
    out << "Soluzione 01\nLo zaino contiene i seguenti elementi:\n";
    for(auto i : solution01) {
        out << "Valore: " << i.value << "\nPeso: " << i.weight << "\n";
    }
    out << "----------------------------\n";
    out << "Soluzione frazionale\nLo zaino contiene i seguenti elementi:\n";
    for(auto i : fractionalSolution) {
        out << "Valore: " << i.first.value << "\nPeso: " << i.first.weight << "\nFrazione: " << i.second << "\n";
    }
    out.close();
    std::cout << "Creato il file di output\n";
    return 0;
}