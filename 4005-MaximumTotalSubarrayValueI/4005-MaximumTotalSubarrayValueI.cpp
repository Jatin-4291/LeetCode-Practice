// Last updated: 9/21/2025, 8:47:10 PM
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long mx = *max_element(nums.begin(), nums.end());
        long long mn = *min_element(nums.begin(), nums.end());
        long long x = 1LL * k * (mx - mn);
        return x;
    }
};
