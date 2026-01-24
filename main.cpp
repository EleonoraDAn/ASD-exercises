#include "heapTree.hpp"

int main()
{
    int n = 8;
    int A[n] = {100, 98, 97, 86, 85, 84, 30, 23};
    buildMaxheap(A, n);
    for(int i = 0; i<n; i++) std::cout << A[i] << " ";
    std::cout << std::endl;
    return 0;
}
