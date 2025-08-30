// Last updated: 8/30/2025, 1:23:00 PM
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int ans=INT_MIN;
        vector<int> dp(energy.size(),-1);
        int n=energy.size();
        for(int i=n-1;i>n-1-k;i--){
            dp[i]=energy[i];
        }
        
        for(int i=n-1-k;i>=0;i--){
            dp[i]=energy[i]+dp[i+k];
        }
        for(int i=0;i<dp.size();i++){
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};