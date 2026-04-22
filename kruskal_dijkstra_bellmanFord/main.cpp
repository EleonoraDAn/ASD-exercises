#include "Graph.hpp"
int main() {
    bool pesiNegativi;
    std::ifstream fileInput("../input.txt");
    if(!fileInput.is_open()) {
        std::cout << "Errore nell'apertura del file in input\n";
        return -1;
    }
    int numNodes, numEdges;
    fileInput >> numNodes >> numEdges;
    Graph graph(numNodes);
    for(int i = 0; i<numNodes; i++) {
        int id, val;
        fileInput >> id >> val;
        Node* node = new Node(id, val);
        graph.addNode(node);
    }

    for(int i = 0; i<numEdges; i++) {
        int weight, destId, sourceId;
        fileInput >> sourceId >> destId >> weight;
        Node* destNode = graph.nodes[destId];
        Node* sourceNode = graph.nodes[sourceId];
        if(weight < 0) {
            pesiNegativi = true;
        }
        Edge* edge = new Edge(weight, sourceNode, destNode);
        graph.addEdge(edge);
    }
    fileInput.close();
    Node* source = graph.nodes[0];
    std::ofstream fileOut("../output.txt");
    if(!fileOut.is_open()) {
        std::cout << "Errore nell'apertura del file di output\n";
        return -1;
    }

    std::string bellmanFordResult;
    bellmanFordResult = graph.bellmanFord(source);
    fileOut << "Bellman Ford result: " << bellmanFordResult << "\n";
    fileOut << "DIJKSTRA:\n";
    if(pesiNegativi) {
        fileOut << "Dijkstra non puo' essere eseguito perche' ci sono dei pesi negativi\n";
    } else {

        graph.dijkstra(source);
        for(auto node : graph.nodes) {
            fileOut << "Nodo " << node->id << ": distance = " << node->dist << ", parent = " << graph.parent[node->id] << std::endl;
        }
    }
    fileOut << std::endl;

    std::vector<Edge*> mst_K;
    std::vector<Edge*> mst_P;
    fileOut << "MST KRUSKAL:\n";
    mst_K = graph.kruskal();
    for(Edge* edge : mst_K) {
        int sourceId = edge->source->id;
        int destId = edge->destination->id;
        int weight = edge->weight;
        fileOut << "Source: " << sourceId << "\nDestination: " << destId << "\nWeight: " << weight << std::endl;
        if(edge != mst_K[mst_K.size()-1]) fileOut << "------------------------------------\n";
    }
    fileOut << std::endl;
    fileOut.close();
    std::cout << "Creato il file di output\n";
    return 0;
}