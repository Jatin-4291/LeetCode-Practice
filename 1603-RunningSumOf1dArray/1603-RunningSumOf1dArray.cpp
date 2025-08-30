// Last updated: 8/30/2025, 1:25:18 PM
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        ans[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int temp = nums[i] + nums[i-1];
            ans[i] = temp;
            nums[i] = temp;
        }
        return ans;
    }
};
