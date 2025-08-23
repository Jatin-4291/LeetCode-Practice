// Last updated: 8/23/2025, 2:35:22 PM
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int p = -1, q = -1;
        int i = 1;
        int n = nums.size();
        while (i < n && nums[i] > nums[i - 1]) {
            p = i;
            i++;
        }
        while (i < n-1 && nums[i] < nums[i - 1]) {
            q = i;
            i++;
        }
        while (i < n && nums[i] > nums[i - 1]) {
            i++;
        }
        if (p != -1 && q != -1 && i == n)
            return true;

        return false;
    }
};
