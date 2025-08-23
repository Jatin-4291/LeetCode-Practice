// Last updated: 8/23/2025, 2:38:14 PM
class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        if (__builtin_popcount(n) != 1) return false;
        while (n > 1) {
            n >>= 2;
        }
        return n == 1;
    }
};
