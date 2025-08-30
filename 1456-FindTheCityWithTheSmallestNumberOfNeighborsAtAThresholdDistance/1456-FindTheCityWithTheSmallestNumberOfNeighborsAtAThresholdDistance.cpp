// Last updated: 8/30/2025, 1:25:30 PM
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> matrix(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++) matrix[i][i] = 0;

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            matrix[u][v] = w;
            matrix[v][u] = w;
        }

        // Floyd-Warshall
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (matrix[i][k] != INT_MAX && matrix[k][j] != INT_MAX)
                        matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }

        int minCity = INT_MAX, ans = -1;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] <= distanceThreshold) cnt++;
            }
            if (cnt <= minCity) {
                minCity = cnt;
                ans = i;
            }
        }

        return ans;
    }
};
