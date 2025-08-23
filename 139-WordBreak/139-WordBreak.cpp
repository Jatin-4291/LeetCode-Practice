// Last updated: 8/23/2025, 2:39:18 PM
class Solution {
public:
    bool solve(int i, string& s, unordered_set<string>& wordSet, unordered_map<int, bool>& dp) {
        if (i >= s.size()) return true;
        if (dp.count(i)) return dp[i];

        for (int j = i; j < s.size(); j++) {
            string x = s.substr(i, j - i + 1);
            if (wordSet.find(x) != wordSet.end()) {
                if (solve(j + 1, s, wordSet, dp)) {
                    return dp[i] = true;
                }
            }
        }
        return dp[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        unordered_map<int, bool> dp;
        return solve(0, s, wordSet, dp);
    }
};
