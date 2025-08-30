// Last updated: 8/30/2025, 1:23:37 PM
class Solution {
public:
    long long maximumSumOfHeights(vector<int>& heights) {
        int n = heights.size();
        long long maxSum = 0;

        for (int peak = 0; peak < n; ++peak) {
            long long sum = heights[peak];
            int minLeft = heights[peak];
            for (int i = peak - 1; i >= 0; --i) {
                minLeft = min(minLeft, heights[i]);
                sum += minLeft;
            }
            int minRight = heights[peak];
            for (int i = peak + 1; i < n; ++i) {
                minRight = min(minRight, heights[i]);
                sum += minRight;
            }

            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};
