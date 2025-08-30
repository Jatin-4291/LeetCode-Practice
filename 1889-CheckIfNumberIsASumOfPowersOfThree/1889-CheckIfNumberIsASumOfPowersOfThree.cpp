// Last updated: 8/30/2025, 1:25:00 PM
class Solution {
public:
    bool solve(int i, int sum, int n) {
        if (sum > n) return false;
        if (sum == n) return true;
        if (i > 16) return false;

        return solve(i + 1, sum + pow(3, i), n) || solve(i + 1, sum, n);
    }

    bool checkPowersOfThree(int n) {
        return solve(0, 0, n);
    }
};
