// Last updated: 8/30/2025, 1:24:21 PM
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int l = 0, r = 0, ans = 0, prev = 0;
        
        while (r < nums.size()) {
            // If adding nums[r] violates the "nice" condition
            while ((prev & nums[r]) != 0) {
                prev ^= nums[l];  // Remove nums[l] from the bitmask
                l++;
            }
            prev |= nums[r];
            ans = max(ans, r - l + 1);
            r++;
        }
        
        return ans;
    }
};
