// Last updated: 8/23/2025, 2:40:26 PM
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int breakP = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                breakP = i;
                break;
            }
        }
        if (breakP != -1) {
            for (int i = n - 1; i > breakP; i--) {
                if (nums[i] > nums[breakP]) {
                    swap(nums[i], nums[breakP]);
                    break;
                }
            }
        }
        reverse(nums.begin() + breakP + 1, nums.end());
    }
};
