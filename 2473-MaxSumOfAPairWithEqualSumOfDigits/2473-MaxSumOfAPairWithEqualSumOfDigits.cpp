// Last updated: 8/30/2025, 1:24:22 PM
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0, x = nums[i];
            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }
            mp[sum].push_back(nums[i]);
        }

        int ans = -1;
        for (auto &i : mp) {
            if (i.second.size() > 1) {
                sort(i.second.rbegin(), i.second.rend());  
                ans = max(ans, i.second[0] + i.second[1]); 
            }
        }
        
        return ans;
    }
};