// Last updated: 8/23/2025, 2:40:36 PM
class Solution {
public:
    void solve(string digits, int i, unordered_map<int, string> mp,
               vector<string>& ans, string temp) {
        if (i >= digits.size()) {
            ans.push_back(temp);
            return;
        }
        for (int j = 0; j < mp[digits[i] - '0'].size(); j++) {
            temp += mp[digits[i] - '0'][j];
            solve(digits, i + 1, mp, ans, temp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<int, string> mp = {{2, "abc"}, {3, "def"}, {4, "ghi"},
                                         {5, "jkl"}, {6, "mno"}, {7, "pqrs"},
                                         {8, "tuv"}, {9, "wxyz"}};
        vector<string> ans;
        if (digits.size() == 0) return vector<string>();
        solve(digits, 0, mp, ans, "");
        return ans;
    }
};