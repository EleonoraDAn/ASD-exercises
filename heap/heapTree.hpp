#ifndef HEAPTREE_HPP
#define HEAPTREE_HPP

#include "Node.hpp"
#include <vector>
#include <stdexcept>
template <typename T>
class heapTree {
private:
    std::vector<Node<T>*> nodes;
    int heapSize;
    
    int getHeapSize() {
        return heapSize;
    }
    
    void swap(Node<T>* &a, Node<T>* &b) {
        Node<T>* temp = a;
        a = b;
        b = temp;
    }

    void maxHeapify(int i) {
        int l = i * 2 + 1;
        int r = i * 2 + 2;
        int max = i;

        if(l < heapSize && nodes[l]->getValue() > nodes[max]->getValue()) {
            max = l;
        }
        
        if(r < heapSize && nodes[r]->getValue() > nodes[max]->getValue()) {
            max = r;
        }

        if(max != i) {
            swap(nodes[i], nodes[max]);
            maxHeapify(max);
        }
    }

    
    void buildMaxHeap() {
        for(int i = (heapSize/2) - 1; i>=0; i--) {
            maxHeapify(i);
        }
    }
public:
    heapTree(std::vector<Node<T>*> &numbers):nodes(numbers) {
        heapSize = numbers.size();
        buildMaxHeap();
    }
    
    T getMax() const {
        return nodes[0]->getValue();
    }

    T extractMax() {
        if(heapSize == 0) {
            throw std::out_of_range("Heap underflow!");
        }
        T max = getMax();
        nodes[0] = nodes[heapSize - 1];
        heapSize --;
        nodes.pop_back();
        maxHeapify(0);
        return max;
    }

    
    std::vector<Node<T>*> getNodes() {
        return nodes;
    }

    
    void insert(T key) {
        heapSize ++;
        nodes.push_back(new Node<T>(key));
        int i = heapSize - 1;
        while(i>=0 && nodes[(i-1)/2]->getValue() < nodes[i]->getValue()) {
            swap(nodes[i], nodes[(i-1)/2]);
            i = (i-1)/2;
        }
    }

    
    void heapSort() {
        buildMaxHeap();
        for(int j = heapSize - 1; j>=1; j--) {
            swap(nodes[0], nodes[j]);
            heapSize --;
            maxHeapify(0);
        }
    }

    ~heapTree() {
        for(Node<T>* n : nodes) {
            delete n;
        }
        nodes.clear();
    }

};

#endif