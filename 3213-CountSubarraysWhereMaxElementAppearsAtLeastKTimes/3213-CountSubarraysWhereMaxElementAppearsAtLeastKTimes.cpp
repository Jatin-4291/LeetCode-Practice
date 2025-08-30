// Last updated: 8/30/2025, 1:23:22 PM
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxElement = 0;
        for (int i = 0; i < nums.size(); i++) {
            maxElement = max(maxElement, nums[i]);
        }
        int n = nums.size();
        long long count = 0; 
        long long ans = 0; 
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == maxElement) {
                count++;
            }
            while (count >= k) {
                ans += (n - i);
                if (nums[j] == maxElement) {
                    count--;
                }
                j++;
            }
        }
        return ans;
    }
};
