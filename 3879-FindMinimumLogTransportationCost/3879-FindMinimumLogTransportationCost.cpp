// Last updated: 8/23/2025, 2:35:50 PM
class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        if (n <= k && m <= k) {
            return 0;
        }

        int toDivide = max(n, m);
        int i = 1;
        int j = toDivide - 1;
        long long cost = LLONG_MAX;

        while (i <= j) {
            if (i <= k && j <= k) {
                cost = min(cost, 1LL * i * j);
            }
            i++;
            j--;
        }

        return (cost == LLONG_MAX ? 0 : cost);
    }
};
