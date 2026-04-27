#ifndef EDITINGDISTANCE_HPP
#define EDITINGDISTANCE_HPP
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Node {
    public: 
        std::string word;
        Node* left;
        Node* right;

        Node(std::string word) {
            this->word = word;
            left = right = nullptr;
        }

        int editingDistance(std::string s1, std::string s2) {
            int len1 = s1.length();
            int len2 = s2.length();

            std::vector<std::vector<int>> dp(len1+1, std::vector<int>(len2+1));

            for(int i = 0; i <= len1; i++) {
                for(int j = 0; j <= len2; j++) {
                    if(i == 0) {
                        dp[i][j] = j;
                    } else if(j == 0){
                        dp[i][j] = i;
                    }
                    else if(s1[i-1] == s2[j-1]) {
                        dp[i][j] = dp[i-1][j-1];
                    } else {
                        dp[i][j] = 1 + std::min(dp[i-1][j], std::min(dp[i][j-1], dp[i-1][j-1]));
                    }
                }
            }

            return dp[len1][len2];
        }
};

class Tree{
    public:
        std::vector<Node*> nodes;
        Node* root;
        Tree(std::vector<std::string>& words) {
            root = new Node(words[0]);
            nodes.push_back(root);
            for(int i = 1; i<words.size(); i++) {
                insert(words[i]);
            }

        }

        void insert(std::string word) {
            Node* current = root;
            Node* parent = NULL;
            while(current != NULL) {
                parent = current;
                if(word < current->word) {
                    current = current->left;
                } else if(word > current->word) {
                    current = current->right;
                } else {
                    return;
                }
            }

            Node* newNode = new Node(word);
            if(word < parent->word) {
                parent->left = newNode;
            } else {
                parent->right = newNode;
            }

            nodes.push_back(newNode);
        }

        std::vector<std::string> findWords(std::string word, int k) {
            std::vector<std::string> result;
            for(Node* n : nodes) {
                if(n->editingDistance(n->word, word) == k) {
                    result.push_back(n->word);
                }
            }
            return result;
        }
};


#endif