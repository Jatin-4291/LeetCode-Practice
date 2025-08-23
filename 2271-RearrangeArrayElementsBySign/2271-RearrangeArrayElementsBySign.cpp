// Last updated: 8/23/2025, 2:36:40 PM
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        int i = 0;  // for positive index
        int j = 1;  // for negative index

        for (int k = 0; k < nums.size(); k++) {
            if (nums[k] >= 0) {
                ans[i] = nums[k];
                i += 2;
            } else {
                ans[j] = nums[k];
                j += 2;
            }
        }

        return ans;
    }
};
