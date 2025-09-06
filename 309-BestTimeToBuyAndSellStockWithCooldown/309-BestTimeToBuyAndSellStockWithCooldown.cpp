// Last updated: 9/6/2025, 11:08:28 AM
class Solution {
public:
     int solve(int i, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        if (i >= prices.size()) return 0;
        if (dp[i][buy] != -1) return dp[i][buy];

        int take = 0, dontTake = 0;

        if (buy) {
            dontTake = solve(i + 1, 1, prices, dp);
            take = -prices[i] + solve(i+1, 0, prices, dp);
        } else {
            dontTake = solve(i + 1, 0, prices, dp);
            take = prices[i] + solve(i + 2, 1, prices, dp);
        }

        return dp[i][buy] = max(take, dontTake);
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return solve(0, 1, prices, dp);
    }
};