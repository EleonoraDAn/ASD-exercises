#include "DivideEtImpera.hpp"
int main() {
    std::vector<int> a;
    for(int i = 0; i < 10; i++) {
        a.push_back(i);
    }

    int sum;
    int n = a.size();
    sum = maxSubArray(a, 0, n - 1);
    std::cout << sum << std::endl;
    int x = 4;
    bool result = ricercaBinaria(a, x, 0, n);
    std::cout << result << std::endl;

    return 0;
}