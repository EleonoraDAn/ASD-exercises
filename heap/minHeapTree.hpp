#include <iostream>
#include <vector>
#include <stdexcept>
#include "Node.hpp"
#include "heapTree.hpp"
template <typename T>
class minHeapTree
{
private:
    std::vector<Node<T>*> nodes;
    int heapSize;
    void buildMinHeap() {
        for(int i=(heapSize/2)-1; i>=0; i--) {
            minHeapify(i);
        }
    }
    void minHeapify(int i) {
        int l = (i*2)+1;
        int r = (i*2)+2;
        int min = i;

        if(l<heapSize && nodes[l]->getValue() < nodes[min]->getValue()) {
            min = l;
        }

        if(r<heapSize && nodes[r]->getValue() < nodes[min]->getValue()) {
            min = r;
        }

        if(min != i) {
            swap(nodes[i], nodes[min]);
            minHeapify(min);
        }
    }
    void swap(Node<T>* &a, Node<T>* &b) {
        Node<T>* temp = a;
        a = b;
        b = temp;
    }
public:
    minHeapTree(std::vector<Node<T>*> &numbers):nodes(numbers), heapSize(nodes.size()) {
        buildMinHeap();
    }
    ~minHeapTree() {
        for(Node<T>* n:nodes) {
            delete n;
        }
        nodes.clear();
    }

    T getMin() {
        return nodes[0]->getValue();
    }

    int getHeapSize() {
        return heapSize;
    }

    T extractMin() {
        if(heapSize == 0) {
            throw std::out_of_range("Underflow dell'heap!");
        }
        int min = getMin();
        nodes[0] = nodes[heapSize - 1];
        heapSize --;
        nodes.pop_back();
        minHeapify(0);
        return min;
    }

    void heapSort() { // ordine decrescente
        buildMinHeap();
        for(int j = heapSize - 1; j>=1; j--) {
            swap(nodes[0], nodes[j]);
            heapSize --;
            minHeapify(0);
        }
    }

    void insert(T key) {
        heapSize ++;
        nodes.push_back(new Node<T>(key));
        int i = heapSize - 1;
        while(i>=0 && nodes[(i-1)/2]->getValue() > nodes[i]->getValue()) {
            swap(nodes[i], nodes[(i-1)/2]);
            i = (i-1)/2;
        }
    }

    std::vector<Node<T>*> getNodes() {
        return nodes;
    }
    
};

