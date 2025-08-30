// Last updated: 8/30/2025, 1:23:13 PM
class Solution {
public:
    int n;
    vector<int> nums;

    int solve(int i, int j, int prevSum, vector<vector<int>>& dp) {
        if (i >= j) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int res = 0;
        if (i + 1 < n && nums[i] + nums[i + 1] == prevSum) {
            res = max(res, 1 + solve(i + 2, j, prevSum, dp));
        }
        if (nums[i] + nums[j] == prevSum) {
            res = max(res, 1 + solve(i + 1, j - 1, prevSum, dp));
        }
        if (j - 1 >= 0 && nums[j] + nums[j - 1] == prevSum) {
            res = max(res, 1 + solve(i, j - 2, prevSum, dp));
        }

        return dp[i][j] = res;
    }

    int maxOperations(vector<int>& nums_) {
        nums = nums_;
        n = nums.size();
        int ans = 0;

        // Try all three valid starting pair combinations
        if (n >= 2) {
            // Case 1: nums[0] + nums[1]
            vector<vector<int>> dp1(n, vector<int>(n, -1));
            ans = max(ans, 1 + solve(2, n - 1, nums[0] + nums[1], dp1));

            // Case 2: nums[0] + nums[n-1]
            vector<vector<int>> dp2(n, vector<int>(n, -1));
            ans = max(ans, 1 + solve(1, n - 2, nums[0] + nums[n - 1], dp2));

            // Case 3: nums[n-2] + nums[n-1]
            vector<vector<int>> dp3(n, vector<int>(n, -1));
            ans = max(ans, 1 + solve(0, n - 3, nums[n - 2] + nums[n - 1], dp3));
        }

        return ans;
    }
};
