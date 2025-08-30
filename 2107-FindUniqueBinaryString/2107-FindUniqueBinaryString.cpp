// Last updated: 8/30/2025, 1:24:47 PM
class Solution {
public:
    void check(unordered_map<string, int>& mp, int size, int i, string temp, string& ans) {
        if (i > size) {
            return;
        }
        if (i == size) {
            if (mp.find(temp) == mp.end()) {
                ans = temp;
            }
            return;
        }
        for (int j = 0; j <= 1; j++) {
            temp += to_string(j);
            check(mp, size, i + 1, temp, ans);
            temp.pop_back();
        }
    }
    
    string findDifferentBinaryString(vector<string>& nums) {
        int size = nums[0].size();
        unordered_map<string, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = 1;
        }
        
        string temp;
        string ans;
        check(mp, size, 0, temp, ans);
        return ans;
    }
};