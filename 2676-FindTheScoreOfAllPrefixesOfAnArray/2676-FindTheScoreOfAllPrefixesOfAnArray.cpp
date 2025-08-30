// Last updated: 8/30/2025, 1:24:04 PM
class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        long long score = 0;
        
        vector<long long> ans;
        ans.reserve(n);  // Pre-allocate memory for efficiency

        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            long long x = static_cast<long long>(maxi) + nums[i];  // Ensure long long
            score += x;
            ans.emplace_back(score);  // Use emplace_back for efficiency
        }
        return ans;
    }
};
