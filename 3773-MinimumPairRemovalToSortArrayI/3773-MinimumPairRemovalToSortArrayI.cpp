// Last updated: 8/30/2025, 1:21:44 PM
#include <vector>
#include <climits>
#include <iostream>

class Solution {
public:
    bool isSorted(const std::vector<int>& nums){
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                return false;
            }
        }
        return true;
    }

    int minimumPairRemoval(std::vector<int>& nums) {
        int ans = 0;
        while (!isSorted(nums)) {
            int sum = 0;
            int m = INT_MAX;
            int x = 0;
            int y = 0;

            // Find the pair with the smallest sum
            for (int i = 0; i < nums.size() - 1; i++) {
                sum = nums[i] + nums[i + 1];
                if (sum < m) {
                    m = sum;
                    x = i;
                    y = i + 1;
                }
            }
            
            // Replace the two elements at x and y with their sum
            nums[x] = m;
            nums.erase(nums.begin() + y);  // Erase the second element since it's merged into x

            ans++;
        }
        return ans;
    }
};

