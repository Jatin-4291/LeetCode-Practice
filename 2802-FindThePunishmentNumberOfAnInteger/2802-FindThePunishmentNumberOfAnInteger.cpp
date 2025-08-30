// Last updated: 8/30/2025, 1:23:56 PM
class Solution {
public:
    bool solve(int i, int x, int sum) {
        if (x == 0) {
            return sum == i;
        }
        int part = 0, factor = 1;
        while (x > 0) {
            part = factor * (x % 10) + part;
            x /= 10;
            factor *= 10;
            if (solve(i, x, sum + part)) {
                return true;
            }
        }
        return false;
    }

    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int x = i * i;
            if (solve(i, x, 0)) {
                ans += x;
            }
        }
        return ans;
    }
};
