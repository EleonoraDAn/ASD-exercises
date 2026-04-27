#ifndef DIVIDEETIMPERA_HPP
#define DIVIDEETIMPERA_HPP

#include <iostream>
#include <vector>

int maxCrossingSum(std::vector<int> a, int l, int m, int h) {
    int sum = 0;
    int leftSum = INT_MIN;
    for(int i = m; i >= 1; i--) {
        sum = sum + a[i];

        if(sum>leftSum) {
            leftSum = sum;
        }
    }

    sum = 0;
    int rightSum = INT_MIN;
    for(int i = m + 1; i <= h; i++) {
        sum = sum + a[i];
        if(sum > rightSum) {
            rightSum = sum;
        }
    }
    return leftSum + rightSum;
}

int maxSubArray(std::vector<int> a, int l, int h) {
    if(l == h) {
        return a[l];
    }

    int m = (l + h)/2;
    int leftSum = maxSubArray(a, l, m);
    int rightSum = maxSubArray(a, m + 1, h);
    int crossSum = maxCrossingSum(a, l, m, h);

    return std::max(std::max(leftSum, rightSum), crossSum);
}

bool ricercaBinaria(std::vector<int> a, int x, int low, int high) {
    int mid = (low + high)/2;
    if(a[mid] == x) {
        return true;
    } else if(high <= low) {
        return false;
    } else if(x < a[mid]) {
        return ricercaBinaria(a, x, low, mid-1);
    } else {
        return ricercaBinaria(a, x, mid + 1, high);
    }
}
#endif