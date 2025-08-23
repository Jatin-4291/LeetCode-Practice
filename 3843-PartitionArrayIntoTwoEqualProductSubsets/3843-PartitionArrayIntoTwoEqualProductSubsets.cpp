// Last updated: 8/23/2025, 2:36:04 PM
class Solution {
public:
    vector<int> nums;
    long long target;

    bool dfs(int i, unsigned long long prod1, unsigned long long prod2, int count1, int count2) {
        if (prod1 > target || prod2 > target) return false;
        if (i == nums.size()) {
            return count1 > 0 && count2 > 0 && prod1 == target && prod2 == target;
        }
        if (dfs(i + 1, prod1 * nums[i], prod2, count1 + 1, count2)) return true;
        if (dfs(i + 1, prod1, prod2 * nums[i], count1, count2 + 1)) return true;

        return false;
    }

    bool checkEqualPartitions(vector<int>& inputNums, long long inputTarget) {
        nums = inputNums;
        target = inputTarget;

        return dfs(0, 1ULL, 1ULL, 0, 0);
    }
};
