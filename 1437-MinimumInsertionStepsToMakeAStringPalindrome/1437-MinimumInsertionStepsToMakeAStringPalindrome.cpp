// Last updated: 8/30/2025, 1:25:32 PM
class Solution {
public:
    int solve(string &s, int i, int j, vector<vector<int>>& dp) {
        if (i > j) {
            return 0;
        }
        if (i == j) {
            return 1;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (s[i] == s[j]) {
            return dp[i][j] = 2 + solve(s, i + 1, j - 1, dp);
        }
        int takeLeft = solve(s, i + 1, j, dp);
        int takeRight = solve(s, i, j - 1, dp);
        return dp[i][j] = max(takeLeft, takeRight);
    }
    int minInsertions(string s) {
          int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return n-solve(s, 0, n - 1, dp);

    }
};