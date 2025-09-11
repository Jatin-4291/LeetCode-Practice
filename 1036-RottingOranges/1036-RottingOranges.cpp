// Last updated: 9/11/2025, 11:01:10 PM
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;

        // Push all initially rotten oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        // Directions: up, down, left, right
        vector<vector<int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
        int minutes = -1; // start from -1, because after last loop we add extra minute

        while (!q.empty()) {
            int sz = q.size();
            for (int k = 0; k < sz; k++) {
                auto [r, c] = q.front();
                q.pop();

                for (auto dir : directions) {
                    int nr = r + dir[0];
                    int nc = c + dir[1];

                    if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                        grid[nr][nc] == 1) {
                        grid[nr][nc] = 2; 
                        q.push({nr, nc});
                    }
                }
            }
            minutes++;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return (minutes == -1 ? 0 : minutes);
    }
};
