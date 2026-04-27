#include "Ordinamenti.hpp"
int main() {
    std::vector<int> numbers = {0, 5, 4, 9, 22, 44, 7};
    radixSort(numbers);

    for(int i : numbers) {
        std::cout << i << " ";
    }
    return 0;
}