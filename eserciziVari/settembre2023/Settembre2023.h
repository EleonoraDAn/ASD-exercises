#ifndef SETTEMBRE2023_H
#define SETTEMBRE2023_H

#include <iostream>
#include <vector>
#include <fstream>
/*.Implementa una hash table ad indirizzamento aperto in c++ di tipo char , int.
Implementa un find ed un delete
*/
using namespace std;

class Item{
public:
    char c;
    int n;
    Item(char c, int n) {
    this->c = c;
    this->n = n;
    }
};

class hashTable {
public:
    int m;
    vector<Item*> table;
    Item* DELECTED;

    hashTable(int m) {
    this->m = m;
    table.resize(m, nullptr);
    DELECTED = new Item('D', -1);
    }

    int hashLineare(int k, int i) {
        return (k+i)%m;}

    int hashQuad(int k, int i) {
        return (k + i + i * i)%m;}

    int hashDoppio(int k, int i) {
        int h1 = k % m;
        int h2 = i + (k%(m-1));
        return (h1 + h2 * i)%m;
    }

    void hashInsert(Item* item) {
        int i = 0;
        while(i!=m) {
            int j = hashLineare(item->n, i); // hashLineare((int)item->c, i) se la chiave fosse il carattere c
            if(table[j] == nullptr || table[j] == DELECTED) {
                table[j] = item;
                return;
            } else {
                i ++;
            }
        }
        cout << "Errore underflow\n";
    }

    Item* hashInsert(int k) {
        int i = 0;
        int j = hashLineare(k, 0);
        while(table[j] != nullptr && i != m) {
            if(table[j] != DELECTED && table[j]->n == k) {
                return table[j];
            } else {
                i++;
                j = hashLineare(k, i);
            }
        }
        return nullptr;
    }

    void hashDelete(int k) {
        int i = 0;
        int j = hashLineare(k, 0);
        while(i!=m && table[j] != nullptr) {
            if(table[j]->n == k && table[j] != DELECTED) {
                delete table[j];
                table[j] = DELECTED;
                return;
            }
                i++;
                j = hashLineare(k, i);

        }
        cout << "Elemento non trovato, impossibile eliminare\n";

    }

    void print(ofstream& of) {
        if (!of.is_open()) {
            cout << "Errore: file di output non aperto!\n";
            return;
        }
            for(int i = 0; i < m; i++) {
                of << "[" << i << "]:";
                if(table[i] == DELECTED) of << "DELECTED\n";
                else if(table[i] == nullptr) of << "NULL\n";
                else of << "<" << table[i]->n << "," << table[i]->c << ">\n";
            }


    }
};
#endif // SETTEMBRE2023_H
