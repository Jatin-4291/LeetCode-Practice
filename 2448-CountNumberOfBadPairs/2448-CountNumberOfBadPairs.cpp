// Last updated: 8/30/2025, 1:24:25 PM
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i] - i]++;
        }
        
        long long n = nums.size();
        long long x = 0;
        
        for (auto& i : mp) {
            if (i.second > 1) {
                x += (static_cast<long long>(i.second) * (i.second - 1)) / 2;
            }
        }
        
        long long ans = (n * (n - 1)) / 2 - x;
        return ans;
    }
};
