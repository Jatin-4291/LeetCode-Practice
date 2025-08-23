// Last updated: 8/23/2025, 2:36:44 PM
class Solution {
public:
    int solve(int i, int x, vector<int>& nums, int maxOR) {
        if (i >= nums.size()) {
            if (x == maxOR) {
                return 1;
            }
            return 0;
        }
        int count = 0;
        count += solve(i + 1, x | nums[i], nums, maxOR);
        count += solve(i + 1, x, nums, maxOR);
        return count;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOR = 0;
        for (int i = 0; i < nums.size(); i++) {
            maxOR |= nums[i];
        }
        return solve(0, 0, nums, maxOR);
    }
};