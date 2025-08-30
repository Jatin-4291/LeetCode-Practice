// Last updated: 8/30/2025, 1:23:01 PM
class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int x=0;
            for(int j=i;j<nums.size();j++){
                x=x|nums[j];
                if(x>=k){
                    ans=min(ans,j-i+1);
                }
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
        
    }
};
