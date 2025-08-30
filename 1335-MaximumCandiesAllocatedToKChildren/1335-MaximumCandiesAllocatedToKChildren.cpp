// Last updated: 8/30/2025, 1:25:38 PM
class Solution {
public:
    long long findCount(vector<int>& candies, int mid) {
        long long count = 0;  // Use long long to prevent overflow
        for (int i = 0; i < candies.size(); i++) {
            count += (candies[i] / mid);
        }
        return count;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        int num = *max_element(candies.begin(), candies.end()); // Find max efficiently
        
        long long l = 1, h = num;
        int ans = 0;

        while (l <= h) {
            long long mid = l + (h - l) / 2;
            long long count = findCount(candies, mid); // Ensure it returns long long

            if (count >= k) {
                ans = mid;
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return ans;
    }
};
