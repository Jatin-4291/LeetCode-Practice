// Last updated: 9/6/2025, 11:08:22 AM
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> hash(n);
        sort(nums.begin(), nums.end()); 
        for(int i=0;i<n;i++){
            hash[i]=i;
        }
        int ans=1;
        int ansIdx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if((nums[i]%nums[j]==0 || nums[j]%nums[i]==0)&& dp[i]<1+dp[j]){
                    dp[i]=1+dp[j];
                    hash[i]=j;
                }
            }
            if(ans<dp[i]){
                ans=dp[i];
                ansIdx=i;
            }
        }
        vector<int> res;
        while(hash[ansIdx]!=ansIdx){
            res.push_back(nums[ansIdx]);
            ansIdx = hash[ansIdx];
        }
        res.push_back(nums[ansIdx]);
        reverse(res.begin(), res.end());
        return res;
    }
};