#include "heapTree.hpp"
#include <vector>
#include <iostream>
int main()
{
    std::vector<int> numeri = {100, 98, 97, 86, 85, 84, 30, 23};
    std::vector<Node<int>*> numbers;

    for(int n : numeri) {
        numbers.push_back(new Node<int>(n));
    }

    heapTree<int> h1(numbers);
    for(Node<int>* n : h1.getNodes()) {
        std::cout << n->getValue() << std::endl;
    }

    h1.insert(50);
    std::cout << "Dopo l'inserimento\n";
    for(Node<int>* n : h1.getNodes()) {
        std::cout << n->getValue() << std::endl;
    }

    std::cout << "Il valore massimo nell'heap e': " << h1.getMax() << std::endl;

    h1.extractMax();
    std::cout << "Dopo l'estrazione del max\n";
    for(Node<int>* n : h1.getNodes()) {
        std::cout << n->getValue() << std::endl;
    }

    h1.heapSort();
    std::cout << "Dopo l'heapsort\n";
    for(Node<int>* n : h1.getNodes()) {
        std::cout << n->getValue() << std::endl;
    }
    h1.~heapTree();
    return 0;
}
