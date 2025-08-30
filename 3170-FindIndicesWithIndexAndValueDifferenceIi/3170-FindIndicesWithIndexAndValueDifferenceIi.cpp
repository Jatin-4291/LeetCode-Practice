// Last updated: 8/30/2025, 1:23:29 PM
class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n = nums.size();

        // dp[i] = { {minValue, minIndex}, {maxValue, maxIndex} }
        vector<pair<pair<int, int>, pair<int, int>>> dp(n);
        dp[n - 1] = { {nums[n - 1], n - 1}, {nums[n - 1], n - 1} };

        for (int i = n - 2; i >= 0; i--) {
            dp[i] = dp[i + 1];

            if (nums[i] < dp[i].first.first) {
                dp[i].first = {nums[i], i};
            }

            if (nums[i] > dp[i].second.first) {
                dp[i].second = {nums[i], i};
            }
        }

        for (int i = 0; i <= n - 1 - indexDifference; i++) {
            auto [minPair, maxPair] = dp[i + indexDifference];

            if (abs(minPair.first - nums[i]) >= valueDifference) {
                return {i, minPair.second};
            }

            if (abs(maxPair.first - nums[i]) >= valueDifference) {
                return {i, maxPair.second};
            }
        }

        return {-1, -1};
    }
};
