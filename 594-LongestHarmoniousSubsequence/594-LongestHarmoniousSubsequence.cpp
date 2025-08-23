// Last updated: 8/23/2025, 2:37:48 PM
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans=0;
        sort(nums.begin(),nums.end());
        int i=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]-nums[i]==1){
                ans=max(ans,j-i+1);
            }
            while(nums[j]-nums[i]>1){
                i++;
            }
        }
        return ans;
    }
};