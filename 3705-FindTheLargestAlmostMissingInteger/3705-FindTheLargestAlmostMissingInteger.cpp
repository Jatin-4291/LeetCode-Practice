// Last updated: 8/30/2025, 1:22:00 PM
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> hm;

        for (int i = 0; i <= n - k; i++) {
            int count = 0;
            int j = i;
            unordered_set<int> hs;

            while (count < k && j < n) {
                hs.insert(nums[j]);
                j++;
                count++;
            }

            for (int key : hs) {
                hm[key]++; // Increment frequency count
            }
        }

        int ans = -1;
        for (const auto& [key, value] : hm) {
            if (value == 1) {
                ans = max(ans, key);
            }
        }

        return ans;
    }
};
