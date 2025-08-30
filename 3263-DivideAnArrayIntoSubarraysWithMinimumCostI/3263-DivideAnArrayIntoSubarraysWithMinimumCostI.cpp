// Last updated: 8/30/2025, 1:23:18 PM
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int first=nums[0];
        int ans=INT_MAX;
        for(int i=1;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                ans=min(ans,first+nums[i]+nums[j]);
            }
        }
        return ans;
    }
};