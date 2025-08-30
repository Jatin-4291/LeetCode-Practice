// Last updated: 8/30/2025, 1:25:08 PM
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<pair<int, int>> directions = {{0,1}, {1,0}, {-1,0}, {0,-1}};

        // Corrected priority_queue declaration
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        pq.push({0, 0, 0});

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int diff = top[0];
            int i = top[1];
            int j = top[2];

            if (vis[i][j]) continue;
            vis[i][j] = true;

            if (i == n - 1 && j == m - 1) return diff;

            for (auto [dr, dc] : directions) {
                int nr = i + dr;
                int nc = j + dc;
                if (nr >= 0 && nc >= 0 && nr < n && nc < m && !vis[nr][nc]) {
                    int newDiff = max(diff, abs(heights[nr][nc] - heights[i][j]));
                    pq.push({newDiff, nr, nc});
                }
            }
        }

        return 0;
    }
};
