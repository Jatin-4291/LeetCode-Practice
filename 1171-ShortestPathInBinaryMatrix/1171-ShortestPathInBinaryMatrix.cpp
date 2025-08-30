// Last updated: 8/30/2025, 1:25:47 PM
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] != 0 || grid[n-1][n-1] != 0)
            return -1;

        // Min-heap: {distance, x, y}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        pq.push({1, 0, 0});
        dist[0][0] = 1;

        vector<pair<int, int>> directions = {
            {-1, 0}, {1, 0}, {0, 1}, {0, -1},
            {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
        };

        while (!pq.empty()) {
            vector<int> top = pq.top();
            pq.pop();

            int d = top[0];
            int x = top[1];
            int y = top[2];

            if (x == n - 1 && y == n - 1)
                return d;

            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;

                if (nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 0) {
                    if (d + 1 < dist[nx][ny]) {
                        dist[nx][ny] = d + 1;
                        pq.push({dist[nx][ny], nx, ny});
                    }
                }
            }
        }

        return -1;
    }
};
