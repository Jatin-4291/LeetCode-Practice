// Last updated: 8/30/2025, 1:23:32 PM
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans=0;
        long long diff=0;
        long long maxi=0;
        for(int i=0;i<nums.size();i++){
            ans=max(ans,diff*nums[i]);
            diff=max(diff,maxi-nums[i]);
            maxi=max(maxi,(long long)nums[i]);
        }
        return ans;
        
    }
};