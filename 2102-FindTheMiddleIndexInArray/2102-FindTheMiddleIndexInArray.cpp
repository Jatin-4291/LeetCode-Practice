// Last updated: 8/30/2025, 1:24:48 PM
class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int ans;
        int left=0;
        int right=sum;
        for(int i=0;i<nums.size();i++){
            right-=nums[i];
            if(left==right){
                return i;
            }
            left+=nums[i];
        }
        return -1;
    }
};