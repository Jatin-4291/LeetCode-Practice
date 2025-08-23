// Last updated: 8/23/2025, 2:36:31 PM
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int maxi = *max_element(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (nums[i] == maxi) {
                int j = i;
                while (j < n && nums[j] == maxi) {
                    j++;
                }
                ans = max(ans, j - i);
                i = j - 1;
            }
        }
        return ans;
    }
};
