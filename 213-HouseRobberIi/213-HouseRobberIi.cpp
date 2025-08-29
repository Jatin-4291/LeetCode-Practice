// Last updated: 8/29/2025, 4:31:15 PM
class Solution {
public:
    int solve(int i, vector<int>& nums, vector<int>& dp) {
        if (i >= nums.size()) return 0;
        if (dp[i] != -1) return dp[i];
        int rob = nums[i] + solve(i + 2, nums, dp);
        int skip = solve(i + 1, nums, dp);
        return dp[i] = max(rob, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> dp1(n, -1), dp2(n, -1);
        vector<int> nums1(nums.begin(), nums.end() - 1); 
        vector<int> nums2(nums.begin() + 1, nums.end()); 

        return max(solve(0, nums1, dp1), solve(0, nums2, dp2));
    }
};
