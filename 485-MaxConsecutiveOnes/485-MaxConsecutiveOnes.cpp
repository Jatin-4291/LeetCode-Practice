// Last updated: 8/23/2025, 2:38:01 PM
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=1){
                count=0;
            }
            else{
            count++;
            ans=max(count,ans);
            }
        }
        return ans;
    }
};