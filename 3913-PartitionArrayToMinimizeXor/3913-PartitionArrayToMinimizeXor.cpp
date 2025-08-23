// Last updated: 8/23/2025, 2:35:38 PM
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int solve(int i, int k, vector<int>& nums, int n, vector<vector<int>>& dp) {
        if (k == 0 && i == n) return 0;
        if (k == 0 || i == n) return INT_MAX;
        if (dp[i][k] != -1) return dp[i][k];

        int res = INT_MAX;
        int currXor = 0;

        for (int j = i; j < n; ++j) {
            currXor ^= nums[j];
            int next = solve(j + 1, k - 1, nums, n, dp);
            if (next != INT_MAX) {
                res = min(res, max(currXor, next));
            }
        }

        return dp[i][k] = res;
    }

    int minXor(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return solve(0, k, nums, n, dp);
    }
};
