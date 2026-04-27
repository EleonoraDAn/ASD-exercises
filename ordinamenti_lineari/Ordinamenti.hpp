#ifndef ORDINAMENTI_HPP
#define ORDINAMENTI_HPP

#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

template<typename T>
void countingSort(std::vector<T>& numbers) {
    T maxVal = *std::max_element(numbers.begin(), numbers.end());
    std::vector<int> cont(maxVal+1);

    for(T& n : numbers) {
        cont[n] ++;
    }

    int index = 0;
    for(int i = 0; i <= maxVal; i++) {
        for(int j = 0; j < cont[i]; j++) {
            numbers[index ++] = i;
        }
    }
}

template<typename T>
void radixSort(std::vector<T>& numbers) {
    T maxVal = *std::max_element(numbers.begin(), numbers.end());
    int numDigits = (int)log10(maxVal)+1;
    for(int i = 0; i < numDigits; i++) {
        std::vector<std::vector<int>> buckets(10);
        int divisor = pow(10, i);
        for(T& num : numbers) {
            int digit = (num/divisor)%10;
            buckets[digit].push_back(num);
        }
        numbers.clear();
        for(auto& bucket : buckets) {
            for(int& num : bucket) {
                numbers.push_back(num);
            }
        }
    }
}
#endif