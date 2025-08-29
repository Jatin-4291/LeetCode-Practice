// Last updated: 8/29/2025, 4:30:57 PM
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        int target = sum / 2;
        int n = nums.size();

        vector<vector<bool>> dp(n+1, vector<bool>(target+1, false));

        // Base Case: If cnt == target, return true
        for (int i = 0; i <= n; i++) {
            dp[i][target] = true; 
        }

        // Filling table from last index back to 0
        for (int i = n-1; i >= 0; i--) {
            for (int cnt = target-1; cnt >= 0; cnt--) {
                bool take = false;
                if (cnt + nums[i] <= target) {
                    take = dp[i+1][cnt + nums[i]];
                }
                bool notTake = dp[i+1][cnt];
                dp[i][cnt] = take || notTake;
            }
        }

        return dp[0][0];
    }
};
