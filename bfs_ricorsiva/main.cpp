#include "Graph.hpp"
int main() {
    std::ifstream fileInput("../input.txt");
    if(!fileInput.is_open()) {
        std::cout << "Errore nell'apertura del file di input\n";
        return -1;
    }
    int numNodes, numEdges;
    Graph<int> graph;
    fileInput >> numNodes >> numEdges;
    for(int i = 0; i<numNodes; i++) {
        int id, val;
        fileInput >> id >> val;
        Node<int>* nodo = new Node(id, val);
        graph.addNode(nodo);
    }
    
    for(int i = 0; i<numEdges; i++) {
        int sourceId, destId;
        fileInput >> sourceId >> destId;
        Node<int>* sourceNode = graph.nodes[sourceId];
        Node<int>* destNode = graph.nodes[destId];
        graph.addEdge(sourceNode, destNode);
    }
    fileInput.close();
    std::ofstream fileOut("../output.txt");
    if(!fileOut.is_open()) {
        std::cout << "Errore nell'apertura del file di output\n";
        return -1;
    }
    Node<int>* sourceNode = graph.nodes[0];
    graph.BFS(sourceNode);
    fileOut << "BFS:\n";
    for(Node<int>* n : graph.nodes) {
        if(n->value == sourceNode->value) continue;
        fileOut << "Id: " << n->id << "\nValore: " << n->value << "\nDistanza dal nodo " << sourceNode->value << ": " << n->dist << "\n";
        if(n->value != graph.nodes[numNodes - 1]->value) fileOut << "----------------------------\n";
    }
    fileOut << std::endl;
    for(Node<int>* n : graph.nodes) {
        n->color = WHITE;
        n->dist = INF;
    }
    sourceNode->dist = 0;
    graph.BfsRicorsiva(sourceNode);
    fileOut << "BFS RICORSIVA:\n";
    for(Node<int>* n : graph.nodes) {
        if(n->value == sourceNode->value) continue;
        fileOut << "Id: " << n->id << "\nValore: " << n->value << "\nDistanza dal nodo " << sourceNode->value << ": " << n->dist << "\n";
        if(n->value != graph.nodes[numNodes - 1]->value) fileOut << "----------------------------\n";
    }
    std::cout << "Creato il file output\n";

    return 0;
}