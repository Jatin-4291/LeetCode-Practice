// Last updated: 8/30/2025, 1:25:19 PM

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0, j = 0;
        int isZero = -1;  // Track the last 0's position
        int ans = 0;

        while (j < nums.size()) {
            if (nums[j] == 0) {
                i = isZero + 1;
                isZero = j;      
            }
            ans = max(ans, j - i);  
            j++;
        }

        return ans;  
    }
};