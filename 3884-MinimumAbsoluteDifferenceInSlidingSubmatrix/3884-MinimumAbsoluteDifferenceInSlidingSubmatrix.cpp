// Last updated: 8/30/2025, 1:21:17 PM
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> a(m - k + 1, vector<int>(n - k + 1));

        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {
                vector<int> vals;

                for (int x = 0; x < k; x++) {
                    for (int y = 0; y < k; y++) {
                        vals.push_back(grid[i + x][j + y]);
                    }
                }

                sort(vals.begin(), vals.end());

                int md = INT_MAX;
                for (int p = 1; p < vals.size(); p++) {
                    int diff = vals[p] - vals[p - 1];
                    if (diff != 0) {
                        md = min(md, diff);
                    }
                }

                a[i][j] = (md == INT_MAX) ? 0 : md;
            }
        }
        return a;
    }
};
