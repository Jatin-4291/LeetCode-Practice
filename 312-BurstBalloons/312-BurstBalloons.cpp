// Last updated: 9/6/2025, 11:08:27 AM
class Solution {
public:
    int solve(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int maxi = 0;
        for (int k = i; k <= j; k++) {
            int coins = nums[i-1] * nums[k] * nums[j+1] 
                      + solve(i, k-1, nums, dp) 
                      + solve(k+1, j, nums, dp);
            maxi = max(maxi, coins);
        }
        return dp[i][j] = maxi;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1); // add 1 at start
        nums.push_back(1);            // add 1 at end
        
        vector<vector<int>> dp(n+2, vector<int>(n+2, -1));
        return solve(1, n, nums, dp);
    }
};
