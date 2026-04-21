#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <fstream>

class Node {
    public:
        int frequenza;
        Node* left;
        Node* right;
        char carattere;

        Node(char carattere, int frequenza) {
            this->carattere = carattere;
            this->frequenza = frequenza;
            this->left = this->right = nullptr;
        }
};

class Compare {
    public:
        bool operator()(Node* l, Node* r) {
            return l->frequenza > r->frequenza;
        }
};

class HuffmanTree {
    public:
        Node* root;
        std::unordered_map<char, std::string> codes;
        HuffmanTree(std::string data) {
            std::unordered_map<char, int> freq;
            for(char c:data) {
                freq[c] ++;
            }

            std::priority_queue<Node*, std::vector<Node*>, Compare> pq;
            for(auto pair:freq) {
                pq.push(new Node(pair.first, pair.second));
            }

            while(pq.size() > 1) {
                Node* left = pq.top();
                pq.pop();
                Node* right = pq.top();
                pq.pop();
                Node* parent = new Node('$', left->frequenza + right->frequenza);
                parent->left = left;
                parent->right = right;
                pq.push(parent);
            }

            root = pq.top();
            pq.pop();
            generateCode(root, "");
        }

        void generateCode(Node* node, std::string code) {
            if(node->left == nullptr && node->right == nullptr) {
                codes[node->carattere] = code;
                return;
            }
            generateCode(node->left, code + "0");
            generateCode(node->right, code + "1");
        }

        std::string encode(std::string data) {
            std::string encoded = "";
            for(char c:data) {
                encoded += codes[c];
            }
            return encoded;
        }

        std::string decode(std::string data) {
            std::string decoded = "";
            Node* current = root;
            for(char c:data) {
                if(c == '0') {
                    current = current->left;
                } else {
                    current = current->right;
                }

                if(current->left == nullptr && current->right == nullptr) {
                    decoded += current->carattere;
                    current = root;
                }
            }

            return decoded;
        }

        void getCodes() {
            std::cout << "I caratteri accompagnati dai loro codici prefissi:\n";
            for(auto pair:codes) {
                std::cout << pair.first << "->" << pair.second << "\n";
            }
        }
};

#endif