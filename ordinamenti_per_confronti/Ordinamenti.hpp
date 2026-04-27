#ifndef ORDINAMENTI_HPP
#define ORDINAMENTI_HPP

#include <iostream>
#include <vector>
#include <fstream>

class Array {
    public:
        std::vector<int> A;
        Array(std::vector<int> Arr) : A(Arr) {}

        void swap(int& i, int &j) {
            int temp = i;
            i = j;
            j = temp;
        }

        void compswap(int& i, int& j) {
            if(j < i) {
                swap(i, j);
            }
        }

        void bubbleSort(std::vector<int>& A) {
            for(int i = 0; i < A.size() - 1; i++) {
                for(int j = 1; j < A.size() - i; j++) {
                    compswap(A[j-1], A[j]);
                }
            }
        }

        void insertionSort(std::vector<int>& A) {
            for(int i = 1; i < A.size(); i++) {
                int key = A[i];
                int j = i - 1;
                while(j >= 0 && A[j]>key) {
                    A[j+1] = A[j];
                    j --;
                }
                A[j+1] = key;
            }
        }

        void merge(std::vector<int>& A, int l, int m, int r) {
            int i, j, k;
            int n1 = m - l + 1;
            int n2 = r - m;
            std::vector<int> L, R;
            for(i = 0; i < n1; i++) {
                L.push_back(A[l + i]);
            }

            for(j = 0; j < n2; j++) {
                R.push_back(A[m + 1 + j]);
            }

            i = 0; 
            j = 0;
            k = l;

            while(i < n1 && j < n2) {
                if(L[i] <= R[j]) {
                    A[k] = L[i];
                    i++;
                } else {
                    A[k] = R[j];
                    j ++;
                }
                k ++;
            }

            while(i < n1) {
                A[k] = L[i];
                i ++;
                k ++;
            }

            while(j < n2) {
                A[k] = R[j];
                j ++; 
                k ++;
            }
        }

        void mergeSort(std::vector<int>& A, int p, int q) {
            if(p < q) {
                int r = (p + q) / 2;
                mergeSort(A, p, r);
                mergeSort(A, r + 1, q);
                merge(A, p, r, q);
            }
        }
};

#endif