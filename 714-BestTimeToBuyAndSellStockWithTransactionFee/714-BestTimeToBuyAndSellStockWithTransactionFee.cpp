// Last updated: 9/11/2025, 11:01:28 PM
class Solution {
public:
    int solve(int i, int buy, vector<int>& prices,int fee, vector<vector<int>>& dp) {
        if (i >= prices.size())
            return 0;
        if (dp[i][buy] != -1)
            return dp[i][buy];

        int take = 0, dontTake = 0;

        if (buy) {
            dontTake = solve(i + 1, 1, prices,fee, dp);
            take = -prices[i] + solve(i + 1, 0, prices,fee, dp);
        } else {
            dontTake = solve(i + 1, 0, prices,fee, dp);
            take = (prices[i]-fee) + solve(i + 1, 1, prices,fee, dp);
        }

        return dp[i][buy] = max(take, dontTake);
    }
    int maxProfit(vector<int>& prices, int fee) {
         vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return solve(0, 1, prices,fee, dp);
    }
};