// Last updated: 8/23/2025, 2:38:03 PM
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    for (int d = 0; d < directions.size(); d++) {
                        int dr = directions[d][0];
                        int dc = directions[d][1];
                        int nr = i + dr;
                        int nc = j + dc;
                        if (nr < 0 || nr >= m || nc < 0 || nc >= n || grid[nr][nc] == 0) {
                            count++;
                        }
                    }
                }
            }
        }
        return count;
    }
};
