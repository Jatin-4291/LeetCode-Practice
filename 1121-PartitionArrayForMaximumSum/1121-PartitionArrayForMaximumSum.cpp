// Last updated: 9/6/2025, 1:49:21 PM
class Solution {
public:
    int solve(int i,vector<int>& arr, int k,vector<int>& dp){
        if(i>=arr.size()) return 0;
        int ans=0;
        int maxi=0;
        if(dp[i]!=-1) return dp[i];
        for(int j=i;j<min((int)arr.size(), i + k);j++){
            maxi=max(maxi,arr[j]);
            int sum=(maxi*(j-i+1))+solve(j+1,arr,k,dp);
            ans=max(ans,sum);
        }
        return dp[i]= ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(),-1);
        return solve(0,arr,k,dp);
    }
};