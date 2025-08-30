// Last updated: 8/30/2025, 1:23:16 PM
class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result = nums;

        int i = 0;
        while (i < n) {
            int j = i;
            int pop = __builtin_popcount(nums[i]);
            while (j < n && __builtin_popcount(nums[j]) == pop) {
                j++;
            }
            sort(result.begin() + i, result.begin() + j);
            i = j;
        }

        return is_sorted(result.begin(), result.end());
    }
};
