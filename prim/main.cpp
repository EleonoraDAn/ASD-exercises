#include "Grafo.hpp"
int main() {
    int V = 5;
    Grafo grafo(V);

    grafo.aggiungiArco(0, 1, 2);
    grafo.aggiungiArco(0, 3, 6);
    grafo.aggiungiArco(1, 2, 3);
    grafo.aggiungiArco(1, 3, 8);
    grafo.aggiungiArco(1, 4, 5);
    grafo.aggiungiArco(2, 4, 7);
    grafo.aggiungiArco(3, 4, 9);
   
    std::cout << "Costo toale del mst\n";
    std::cout << grafo.prim() << std::endl;
    
    return 0;
}