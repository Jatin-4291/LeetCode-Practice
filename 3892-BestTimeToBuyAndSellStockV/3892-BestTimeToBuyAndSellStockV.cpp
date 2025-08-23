// Last updated: 8/23/2025, 2:35:45 PM
class Solution {
public:
    vector<vector<vector<long long> >>dp;
    long long solve(int x, int k, int flag, vector<int>&prices){
        if(x>=prices.size()){
            if(flag==0) 
          return 0;
          else 
             return INT_MIN;
        }
        else if(k==0 && flag==0)
           return 0;
        else if(dp[x][k][flag]!=-1)
           return dp[x][k][flag];
        if(flag==0){
           dp[x][k][flag]= max(solve(x+1,k,flag,prices),max(
            solve(x+1,k-1,1,prices)-prices[x],
            solve(x+1,k-1,2,prices)+prices[x]));
        }else if(flag==1){
            dp[x][k][flag]= max(solve(x+1,k,flag,prices),
            solve(x+1,k,0,prices)+prices[x]);
        }else if(flag==2){
            dp[x][k][flag]= max(solve(x+1,k,flag,prices),
            solve(x+1,k,0,prices)-prices[x]);
        }
        return dp[x][k][flag];
    
    }
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        dp = vector<vector<vector<long long>>>(n+1,vector<vector<long long>>(k+1,vector<long long>(5,-1)));
        return solve(0,k,0,prices);
    }
};