#include "utils.hpp"

int parent(int i) {
    return (i-1)/2;
}

int left(int i) {
    return 2*i+1;
}

int right(int i) {
    return 2*i+2;
}

void maxHeapify (int A[], int n, int i) {
    int max;
    int p = parent(i);
    int l = left(i);
    int r = right(i);

    if(l<n && A[l]>A[i]) {
        max = l;
    }else {
        max = i;
    }

    if(r<n && A[r]>A[max]) {
        max = r;
    }

    if(max != i) {
        swap(A[i], A[max]);
        maxHeapify(A, n, i);
    }
    
}

void buildMaxheap(int A[], int n) {
    for(int i=(n/2)-1; i>=0; i--) {
    maxHeapify(A, n, i);
    }   
}

