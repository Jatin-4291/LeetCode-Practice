// Last updated: 8/23/2025, 2:36:05 PM
class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i, int j,long long& val) {
        vis[i][j] = true;
        val+=grid[i][j];
        for (auto& dir : directions) {
            int ni = i + dir[0];
            int nj = j + dir[1];
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] != 0 && !vis[ni][nj]) {
                dfs(grid, vis, ni, nj,val);
            }
        }
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0 && !vis[i][j]) {
                    long long val=0;
                    dfs(grid, vis, i, j,val);
                    if(val%k==0){
                        count++;
                    }
                }
            }
        }

        return count;
    }
};
