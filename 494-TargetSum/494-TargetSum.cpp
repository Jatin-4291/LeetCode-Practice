// Last updated: 8/29/2025, 4:30:52 PM
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        int offset = totalSum;
        int width = 2 * totalSum + 1;
        if (abs(target) > totalSum) return 0;

        vector<vector<int>> dp(n + 1, vector<int>(width, 0));
        dp[n][target + offset] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int sum = -totalSum; sum <= totalSum; sum++) {
                int off = sum + offset;
                int add = 0, sub = 0;
                if (off + nums[i] < width) add = dp[i + 1][off + nums[i]];
                if (off - nums[i] >= 0) sub = dp[i + 1][off - nums[i]];
                dp[i][off] = add + sub;
            }
        }
        return dp[0][0 + offset];
    }
};
