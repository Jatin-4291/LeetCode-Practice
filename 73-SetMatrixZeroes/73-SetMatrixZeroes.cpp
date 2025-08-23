// Last updated: 8/23/2025, 2:39:56 PM
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> zeros;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 0) {
                    zeros.push_back({i, j});
                }
            }
        }
        for(const auto& [row, col] : zeros) {
            for(int j = 0; j < m; j++) {
                matrix[row][j] = 0;
            }
            for(int i = 0; i < n; i++) {
                matrix[i][col] = 0;
            }
        }
    }
};
