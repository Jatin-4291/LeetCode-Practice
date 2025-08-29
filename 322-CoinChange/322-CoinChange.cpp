// Last updated: 8/29/2025, 4:31:03 PM
class Solution {
public:
    int solve(vector<int>& coins, int amount, vector<int>& dp){
        if (amount == 0) return 0;
        if (amount < 0) return INT_MAX;
        if (dp[amount] != -1) return dp[amount];

        int ans = INT_MAX;
        for (int coin : coins) {
            int res = solve(coins, amount - coin, dp);
            if (res != INT_MAX) ans = min(ans, 1 + res);
        }
        return dp[amount] = ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        // int ans = solve(coins, amount, dp);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            int ans=INT_MAX;
            for(int j=0;j<coins.size();j++){
                int x=INT_MAX;
                if((i-coins[j])>=0  && dp[i - coins[j]] != INT_MAX){
                x=1+dp[i-coins[j]];
                }else{
                    x=INT_MAX;
                }
                ans=min(ans,x);
            }
            dp[i]=ans;
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
