// Last updated: 8/30/2025, 1:21:15 PM
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        unordered_map<int, int> right;
        unordered_map<int, int> left;
        for (int i = 0; i < n; i++) {
            right[nums[i]]++;
        }

        long long ans = 0;

        for (int j = 0; j < n; j++) {
            right[nums[j]]--;

            int target = nums[j] * 2;

            long long countLeft = left[target];
            long long countRight = right[target];

            ans = (ans + (countLeft * countRight) % MOD) % MOD;

            left[nums[j]]++;
        }

        return ans;
    }
};
