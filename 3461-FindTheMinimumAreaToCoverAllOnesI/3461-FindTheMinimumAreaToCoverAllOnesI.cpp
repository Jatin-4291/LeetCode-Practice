// Last updated: 8/30/2025, 1:22:43 PM
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int startRow = -1, endRow = -1, leftCol = m, rightCol = -1;

        // Find the first and last row containing a '1'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    if (startRow == -1) startRow = i; // First row with 1
                    endRow = i; // Last row with 1
                    leftCol = min(leftCol, j); // Leftmost column with 1
                    rightCol = max(rightCol, j); // Rightmost column with 1
                }
            }
        }

        // If no '1' is found, return 0
        if (startRow == -1) return 0;

        // Calculate the area
        return (endRow - startRow + 1) * (rightCol - leftCol + 1);
    }
};
