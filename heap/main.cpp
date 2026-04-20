#include "heapTree.hpp"
#include "minHeapTree.hpp"
#include <vector>
#include <iostream>
int main()
{
    std::vector<int> numeri = {12, 7, 1, 3, 10, 17, 19, 2, 5};
    std::vector<Node<int>*> numbers;

    for(int n : numeri) {
        numbers.push_back(new Node<int>(n));
    }
    
    heapTree<int> h1(numbers);
    for(Node<int>* n : h1.getNodes()) {
        std::cout << n->getValue() << std::endl;
    }

    h1.insert(25);
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
   

    // std::cout << "+++ MINHEAP +++\n";
    // minHeapTree<int> h2(numbers);   
    // std::cout << "BUILD MINHEAP\n";
    // for(Node<int>* n : h2.getNodes()) {
    //     std::cout << n->getValue() << " ";
    // }
    // std::cout << std::endl;
    // h2.insert(25);
    // std::cout << "Dopo l'inserimento del numero 25\n";
    // for(Node<int>* n : h2.getNodes()) {
    //     std::cout << n->getValue() << " ";
    // }
    // std::cout << std::endl;
    // std::cout << "Il minimo nel min-heap e': " << h2.extractMin() << "\n";
    // std::cout << "Dopo l'estrazione del minimo\n";
    // for(Node<int>* n : h2.getNodes()) {
    //     std::cout << n->getValue() << " ";
    // }
    // std::cout << std::endl;
    // h2.heapSort();
    // std::cout << "Dopo l'heapSort\n";
    // for(Node<int>* n : h2.getNodes()) {
    //     std::cout << n->getValue() << " ";
        
    // }
    // std::cout << std::endl;
    // heapTree h1(numbers);
    // h1.heapSort();
    // std::cout << "Ordine crescente\n";
    // for(Node<int>* n : h1.getNodes()) {
    //     std::cout << n->getValue() << " ";
    // }
    // h2.~minHeapTree();
    // h1.~heapTree();
    return 0;
}
