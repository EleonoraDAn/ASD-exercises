#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include <iostream>
#include <fstream>
#include <vector>

template<typename T>
class Item {
    public:
        T key;
        T value;
        Item(T k, T v) : key(k), value(v) {}
};

template<typename T>
class Hashtable {
    public:
        std::vector<Item<T>*> table;
        int m;
        
        Hashtable(int m) : m(m) {}

        int hashLineare(T key, int i) {
            return (key+i)%m;
        }  
        int hashQuadratico(T key, int i) {
            return (key+i+i*i)%m;
        }  
        int hashDoppio(T key, int i) {
            int hash1 = key % m;
            int hash2 = 1 + (key % (m-1));
            return (hash1 + i * hash2) % m;
        } 
        void insert(Item<T>* item) {
            int i = 0;
            
            while(i != m) {
                int j = hashLineare(item->key, i);
                if(table.size() <= j) {
                    table.resize(j+1, nullptr);
                }

                if(table[j] == nullptr) {
                    table[j] = item;
                    return;
                } else {
                    i ++;
                }
                
            }

            std::cout << "Errore overflow\n";
        }
        Item<T>* search(T key) {
            int i = 0;
            int j = hashLineare(key, 0);
            while(table[j] != nullptr && i != m) {
                if(table[j]->key == key) {
                    return table[j];
                }
                i++;
                j = hashLineare(key, i);
            }
            return nullptr;
        }
};
#endif