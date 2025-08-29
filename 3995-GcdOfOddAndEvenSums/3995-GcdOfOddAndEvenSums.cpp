// Last updated: 8/29/2025, 4:29:05 PM
#include <numeric> // for std::gcd

class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        long long sumEven = n * (n + 1);
        long long sumOdd = (long long)n * n;
        return std::gcd(sumEven, sumOdd);
    }
};
