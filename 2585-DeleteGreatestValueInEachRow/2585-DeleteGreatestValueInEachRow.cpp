// Last updated: 8/30/2025, 1:24:12 PM
class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<priority_queue<int>> pq(n); 

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pq[i].push(grid[i][j]);
            }
        }

        int final = 0;
        for (int j = 0; j < m; j++) {
            int ans = 0;
            for (int i = 0; i < n; i++) {
                ans = max(ans, pq[i].top());
                pq[i].pop();
            }
            final += ans;
        }
        return final;
    }
};
