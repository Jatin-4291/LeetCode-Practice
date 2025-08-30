// Last updated: 8/30/2025, 1:24:55 PM
class Solution {
public:
    int solve(vector<int>& nums,int i,int sum){
        if(i>=nums.size()) return sum;
        int take= solve(nums,i+1,sum^nums[i]);
        int nottake= solve(nums,i+1,sum);
        return take+nottake;
    }
    int subsetXORSum(vector<int>& nums) {
        return solve(nums,0,0);
    }
};