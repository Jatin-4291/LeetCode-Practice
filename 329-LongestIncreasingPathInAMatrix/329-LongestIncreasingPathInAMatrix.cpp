// Last updated: 8/23/2025, 2:38:18 PM
class Solution {
public:
    int dfs(int i, int j,
            vector<vector<int>>& dp, vector<vector<int>>& matrix) {
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        vector<vector<int>> directions = {{-1,0}, {0,-1}, {1,0}, {0,1}};
        int len = 1;
        for (auto& dir : directions) {
            int nr = i + dir[0];
            int nc = j + dir[1];
            if (nr >= 0 && nr < matrix.size() &&
                nc >= 0 && nc < matrix[0].size() &&
                matrix[nr][nc] > matrix[i][j]) {
                len = max(len, 1 + dfs(nr, nc, dp, matrix));
            }
        }
        return dp[i][j] = len;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dfs(i, j, dp, matrix));
            }
        }
        return ans;
    }
};
