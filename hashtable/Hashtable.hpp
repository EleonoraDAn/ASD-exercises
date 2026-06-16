#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

template<typename K, typename T>
class Item {
    public:
        K key;
        T value;
        Item(K k, T v) : key(k), value(v) {}
};

template<typename K, typename T>
class Hashtable {
    public:
        std::vector<Item<K, T>*> table;
        int m;
        Item<K, T>* DELETED;

        Hashtable(int m) : m(m) {
            table.resize(m, nullptr);
            DELETED = new Item<K, T>(-1, "DELETED");
        }

        int hashLineare(K key, int i) {
            return (key+i)%m;
        }  
        int hashQuadratico(K key, int i) {
            return (key+i+i*i)%m;
        }  
        int hashDoppio(K key, int i) {
            int hash1 = key % m;
            int hash2 = 1 + (key % (m-1));
            return (hash1 + i * hash2) % m;
        } 
        void insert(Item<K, T>* item) {
            int i = 0;
            
            while(i != m) {
                int j = hashLineare(item->key, i);
                // if(table.size() <= j) {
                //     table.resize(j+1, nullptr);
                // }

                if(table[j] == nullptr || table[j] == DELETED) {
                    table[j] = item;
                    return;
                } else {
                    i ++;
                }
                
            }

            std::cout << "Errore overflow\n";
        }
        Item<K, T>* search(K key) {
            int i = 0;
            int j = hashLineare(key, 0);
            while(table[j] != nullptr && i != m) {
                if(table[j]->key == key && table[j] != DELETED) {
                    return table[j];
                }
                i++;
                j = hashLineare(key, i);
            }
            return nullptr;
        }

        void remove(K key) {
            int i = 0;
            int j = hashLineare(key, 0);

            while(table[j] != nullptr && i != m) {
                if(table[j] != DELETED && table[j]->key == key) {
                    delete table[j];
                    table[j] = DELETED;
                    std::cout << "Elemento con chiave " << key << " eliminato.\n";
                    return;
                }
                i++;
                j = hashLineare(key, i);
            }
            std::cout << "Chiave non trovata, impossibile eliminare\n";
        }

        void print() {
            for(int i = 0; i < m; i++) {
                std::cout << "[" << i << "]: ";
                if(table[i] == nullptr) std::cout << "NULL\n";
                else if(table[i] == DELETED) std::cout << "DELETED\n";
                else std::cout << "<" << table[i]->key << ", " << table[i]->value << ">\n";
            }
        }
};
#endif