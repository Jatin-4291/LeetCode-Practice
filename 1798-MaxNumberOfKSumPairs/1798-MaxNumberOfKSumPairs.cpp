// Last updated: 8/30/2025, 1:25:05 PM
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }

        int count = 0;
        for (int num : nums) {
            int complement = k - num;
            if (mp[num] > 0 && mp[complement] > 0) {
                if (num == complement && mp[num] < 2) continue;
                count++;
                mp[num]--;
                mp[complement]--;
            }
        }

        return count;
    }
};
