#include "ABR.hpp"
int main()
{
    ABR<int> firstAbr;
    // std::vector<int> numbers = {50, 40, 60, 36, 41, 55, 63, 25, 52, 57, 62, 100, 84};
    std::vector<int> numbers = {50, 40, 36, 41, 25}; // non avendo figlio dx, se eliminiamo la root, verrà promosso suo figlio sx e non il predecessore
    std::vector<int> preOrderVisit;
    std::vector<int> postOrderVisit;
    std::vector<int> inOrderVisit;
    Node<int>* predecessore;
    Node<int>* successore;
    int key;
    for(int val : numbers) {
        /* std::cout << "Inserisci un valore\n";
        std::cin >> val; */
        firstAbr.insert(new Node<int>(val));
    }

    std::cout << "L'altezza dell'albero e': " << firstAbr.getHeight(firstAbr.getRoot()) << "\n";

    std::cout << "+++ PREORDER +++\n";
    firstAbr.preOrder(firstAbr.getRoot(), preOrderVisit);
    for(int n : preOrderVisit) {
        std::cout << n << " ";
    }
    std::cout << "\n";

    std::cout << "+++ POSTORDER +++\n";
    firstAbr.postOrder(firstAbr.getRoot(), postOrderVisit);
    for(int n : postOrderVisit) {
        std::cout << n << " ";
    }
    std::cout << "\n";

    std::cout << "+++ INORDER +++\n";
    firstAbr.inOrder(firstAbr.getRoot(), inOrderVisit);
    for(int n : inOrderVisit) {
        std::cout << n << " ";
    }
    std::cout << "\n";

    std::cout << "+++ DELETE +++\n";
    std::cout << "Inserisci il valore da eliminare\n";
    std::cin >> key;
    // il nodo che passiamo come parametro per il calcolo del successore e del predecessore DEVE ESSERE PRESENTE nell'albero
    successore = firstAbr.getSuccessor(firstAbr.searchNode(key));
    predecessore = firstAbr.getPredecessore(firstAbr.searchNode(key));
    if(successore)
        std::cout << "Il successore del nodo da eliminare e': " << successore->getValue() << std::endl;
    else
    std::cout << "Nessun valore e' il successore di questo nodo\n";
    if(predecessore)
        std::cout << "Il predecessore del nodo da eliminare e': " << predecessore->getValue() << std::endl;
    else
        std::cout << "Nessun valore e' il predecessore di questo nodo\n";
    if(firstAbr.searchNode(key)) {
        std::cout << "Il nodo che vuoi eliminare e' presente!\n";
    } else {
        std::cout << "Il nodo che vuoi eliminare non è presente!\n";
    }
    firstAbr.deleteNode(key);
    std::cout << "+++ Dopo l'eliminazione +++\n";
    preOrderVisit.clear();
    firstAbr.preOrder(firstAbr.getRoot(), preOrderVisit);
    for(int n : preOrderVisit) {
        std::cout << n << " ";
    }
    std::cout << "\n";
    
    std::cout << "POST-ELIMINAZIONE\nL'altezza dell'albero e': " << firstAbr.getHeight(firstAbr.getRoot()) << "\n";
    
    return 0;
}
