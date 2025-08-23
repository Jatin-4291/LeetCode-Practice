// Last updated: 8/23/2025, 2:37:50 PM
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum=0;
        for(int i=0;i<nums.size();i+=2){
            sum+=nums[i];
        }
        return sum;
    }
};