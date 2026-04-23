#ifndef KNAPSACK_HPP
#define KNAPSACK_HPP

#include <iostream>
#include <fstream>
#include <vector>

template<typename T>
class Item {
    public:
        T value;
        T weight;
        Item(T value, T weight) : value(value), weight(weight) {}
};

template<typename T>
class Knapsack {
    public:
        std::vector<Item<T>*> items;
        T value;
        T capacity;
        Knapsack(std::vector<Item<T>*> items, T capacity) : items(items), capacity(capacity) {}

        std::vector<Item<T>> solve01() {
            int n = items.size();
            std::vector<Item<T>> solution;
            std::vector<std::vector<T>> maxValues(n + 1, std::vector<T>(capacity + 1, 0));
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= capacity; j++) {
                    if(items[i-1]->weight > j) {
                        maxValues[i][j] = maxValues[i-1][j];
                    } else {
                        maxValues[i][j] = std::max(maxValues[i-1][j], items[i-1]->value + maxValues[i-1][j-items[i-1]->weight]);
                    }
                }
            }

            int i = n;
            int j = capacity;
            while(i > 0 && j > 0) {
                if(maxValues[i][j] != maxValues[i-1][j]) {
                    solution.push_back(*items[i-1]);
                    j -= items[i-1]->weight;
                }
                i--;
            }

            return solution;
        }

        std::vector<std::pair<Item<T>, double>> solveFractional() {
            std::vector<std::pair<Item<T>, double>> x;
            int n = items.size();
            int k = 1;
            T value = 0.0;

            while(k <= n && capacity > 0.0) {
                if(items[k-1]->weight <= capacity) {
                    x.push_back(std::make_pair(*items[k-1], 1.0));
                    value += items[k-1]->value;
                    capacity -= items[k-1]->weight;

                } else {
                    double fraction = capacity/items[k-1]->weight;
                    x.push_back(std::make_pair(*items[k-1], fraction));
                    value += fraction*items[k-1]->value;
                    capacity = 0.0;
                }
                k++;
            } 
            return x;
        }
};
#endif