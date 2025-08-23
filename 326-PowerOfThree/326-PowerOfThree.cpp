// Last updated: 8/23/2025, 2:38:23 PM
class Solution {
public:
    bool isPowerOfThree(int n) {
        const int max_pow = 1162261467;
        return n > 0 && max_pow % n == 0;
    }
};