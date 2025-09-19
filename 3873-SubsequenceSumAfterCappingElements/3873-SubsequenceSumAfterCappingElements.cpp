// Last updated: 9/19/2025, 5:26:21 PM
class Solution {
public:
    vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<bool> result(n, false);

        bitset<10001> dp; // assuming k <= 10000
        dp[0] = 1;
        int idx = 0;

        for (int i = 1; i <= n; i++) {
            while (idx < n && nums[idx] <= i) {
                dp |= (dp << nums[idx]); // add nums[idx] to all existing sums
                idx++;
            }

            if (dp[k]) {
                result[i - 1] = true;
            } else {
                for (int p = idx; p < n; p++) {
                    int rightRemain = p - idx + 1;
                    int needed = k - (rightRemain * i);
                    if (needed >= 0 && dp[needed]) {
                        result[i - 1] = true;
                        break;
                    }
                }
            }
        }
        return result;
    }
};
