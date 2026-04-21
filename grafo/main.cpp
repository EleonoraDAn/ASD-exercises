#include "Grafo.hpp"
int main() {
    std::ifstream fileInput("../inputG.txt");
    if(!fileInput.is_open()) {
        std::cout << "Errore nell'apertura del file di input\n";
        return -1;
    }
    int numNodes, numEdges;
    fileInput >> numNodes >> numEdges;
    std::unordered_map<int, Node<int>*> nodesMap;
    Graph<int> g;
    for(int i = 0; i<numEdges; i++) {
        int sourceVal, destVal, weight;
        fileInput >> sourceVal >> destVal >> weight;
        Node<int>* sourceNode = nullptr;
        auto itSource = nodesMap.find(sourceVal);
        if(itSource == nodesMap.end()) {
            sourceNode = new Node<int>(sourceVal);
            nodesMap[sourceVal] = sourceNode;
            g.addNode(sourceNode);
        } else {
            sourceNode = itSource->second;
        }

        Node<int>* destNode = nullptr;
        auto itDest = nodesMap.find(destVal);
        if(itDest == nodesMap.end()) {
            destNode = new Node<int>(destVal);
            nodesMap[destVal] = destNode;
            g.addNode(destNode);
        } else {
            destNode = itDest->second;
        }

        g.addEdge(sourceNode, destNode, weight);

    }

    fileInput.close();
    g.bfs(nodesMap[0]);
    for(Node<int>* n : g.nodes) {
        if(n->value == nodesMap[0]->value) continue;
        std::cout << "Distanza dal nodo " << nodesMap[0]->value << " al nodo " << n->value << " e': " << n->distance << "\nPercorso dallo start node: " << n->percorso << "\n"; 
    }

    g.dfs();
    for(Node<int>* n : g.nodes) {
        std::cout << "Nodo: " << n->value << "\nDiscovery time: " << n->discovery_time << "\nFinish-time: " << n->finish_time << std::endl;
    }
    return 0;
}