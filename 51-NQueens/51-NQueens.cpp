// Last updated: 8/23/2025, 2:40:12 PM
class Solution {
public:
    bool canPlace(int i, int j, vector<string>& grid) {
        int n = grid.size();
        for (int k = 0; k < n; k++) {
            if (grid[k][j] == 'Q') return false;
            if (grid[i][k] == 'Q') return false;
        }

        for (int a = i - 1, b = j - 1; a >= 0 && b >= 0; a--, b--) {
            if (grid[a][b] == 'Q') return false;
        }
        for (int a = i - 1, b = j + 1; a >= 0 && b < n; a--, b++) {
            if (grid[a][b] == 'Q') return false;
        }
        return true;
    }

    void solve(int i, int n, vector<string>& grid, vector<vector<string>>& res) {
        if (i == n) {
            res.push_back(grid);
            return;
        }
        for (int j = 0; j < n; j++) {
            if (canPlace(i, j, grid)) {
                grid[i][j] = 'Q';
                solve(i + 1, n, grid, res);
                grid[i][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> grid(n, string(n, '.'));
        vector<vector<string>> res;
        solve(0, n, grid, res);
        return res;
    }
};
