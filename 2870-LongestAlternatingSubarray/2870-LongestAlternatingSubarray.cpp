// Last updated: 8/30/2025, 1:23:49 PM
class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int ans = -1;

        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i + 1] - nums[i] != 1) continue;

            int j = i;
            int sign = 1;
            while (j + 1 < nums.size() && nums[j + 1] - nums[j] == sign) {
                sign *= -1;
                ++j;
            }

            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};
