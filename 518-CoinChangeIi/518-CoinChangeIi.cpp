// Last updated: 8/29/2025, 4:30:48 PM
class Solution {
public:
    int rec(int amount, int j, vector<int>& coins, vector<vector<int>>& dp){
        if(amount <= 0){
            if(amount == 0) return 1;
            return 0;
        }
        if(j >= coins.size()) return 0;
        if(dp[amount][j] != -1) return dp[amount][j];

        int take = rec(amount - coins[j], j, coins, dp);
        int not_take = rec(amount, j+1, coins, dp);

        return dp[amount][j] = take + not_take;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(amount+1, vector<int>(n, -1));
        return rec(amount, 0, coins, dp);
    }
};