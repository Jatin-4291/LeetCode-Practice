// Last updated: 8/23/2025, 2:36:18 PM
class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int n = nums.size();
        int mergeCount = 0;
        int j = 0;
        while (j < n) {
            int maxInWindow = nums[j];
            int i = j + 1;
            while (i < n && nums[i] < maxInWindow) {
                maxInWindow = max(maxInWindow, nums[i]);
                i++;
            }
            mergeCount++;
            j = i;
        }

        return mergeCount;
    }
};
