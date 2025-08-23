// Last updated: 8/23/2025, 2:40:09 PM
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(maxReach<i){
                return false;
            }
            maxReach=max(maxReach,i+nums[i]);
            if(maxReach>=n-1){
                return true;
            }
        }
        return false;
    }
};