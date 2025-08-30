// Last updated: 8/30/2025, 1:24:05 PM
#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    bool isPossible(long long mid, std::vector<int>& ranks, int cars) {
        long long sum = 0;
        for (int rank : ranks) {
            sum += std::sqrt(mid / rank); // Corrected sqrt calculation
            if (sum >= cars) return true; // Early exit optimization
        }
        return sum >= cars;
    }

    long long repairCars(std::vector<int>& ranks, int cars) {
        long long low = 1, high = 1LL * (*std::max_element(ranks.begin(), ranks.end())) * cars * cars;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (isPossible(mid, ranks, cars)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
