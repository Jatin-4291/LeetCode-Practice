// Last updated: 8/30/2025, 1:25:49 PM
class Solution {
public:
    bool isPredecessor(int curr, int prev, vector<string>& words) {
        string& shorter = words[prev];
        string& longer = words[curr];
        if (longer.size() != shorter.size() + 1) return false;

        int i = 0, j = 0;
        bool skipped = false;
        while (i < shorter.size() && j < longer.size()) {
            if (shorter[i] == longer[j]) {
                i++; j++;
            } else {
                if (skipped) return false;
                skipped = true;
                j++;
            }
        }
        return true;
    }

    int solve(int i, int prev, vector<string>& words, vector<vector<int>>& dp) {
        if (i == words.size()) return 0;

        if (dp[i][prev + 1] != -1) return dp[i][prev + 1];

        int take = 0;
        if (prev == -1 || isPredecessor(i, prev, words)) {
            take = 1 + solve(i + 1, i, words, dp);
        }

        int notTake = solve(i + 1, prev, words, dp);
        return dp[i][prev + 1] = max(take, notTake);
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });

        int n = words.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(0, -1, words, dp);
    }
};
