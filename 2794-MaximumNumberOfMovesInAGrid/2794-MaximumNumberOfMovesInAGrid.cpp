// Last updated: 8/30/2025, 1:23:57 PM
class Solution {
public:
    int solve(int i, int j, int n, int m, vector<vector<int>>& grid, int prev,vector<vector<int>>& dp) {
        if (i < 0 || i >= n || j >= m) return 0;
        if (grid[i][j] <= prev) return 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int moveForward = solve(i, j + 1, n, m, grid, grid[i][j],dp);
        int moveRight   = solve(i - 1, j + 1, n, m, grid, grid[i][j],dp);
        int moveLeft    = solve(i + 1, j + 1, n, m, grid, grid[i][j],dp);
        
        return dp[i][j]=1 + max({moveForward, moveRight, moveLeft});
    }

    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for (int i = 0; i < n; i++) {
            ans = max(ans, solve(i, 0, n, m, grid, grid[i][0] - 1,dp)); 
        }

        return ans - 1; 
    }
};
