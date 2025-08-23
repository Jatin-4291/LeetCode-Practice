// Last updated: 8/23/2025, 2:36:25 PM
class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            int maxDigit = 0;
            int temp = x;

            while (temp > 0) {
                maxDigit = max(maxDigit, temp % 10);
                temp /= 10;
            }

            mp[maxDigit].push_back(x);
        }

        int ans = -1;
        for (auto& [digit, group] : mp) {
            if (group.size() >= 2) {
                sort(group.begin(), group.end(), greater<int>());
                ans = max(ans, group[0] + group[1]);
            }
        }

        return ans;
    }
};
