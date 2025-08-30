// Last updated: 8/30/2025, 1:22:57 PM
class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<int> rowCount(rows, 0);
        vector<int> colCount(cols, 0);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    long long rowOnes = rowCount[i] - 1;
                    long long colOnes = colCount[j] - 1;
                    ans += rowOnes * colOnes;
                }
            }
        }

        return ans;
    }
};
