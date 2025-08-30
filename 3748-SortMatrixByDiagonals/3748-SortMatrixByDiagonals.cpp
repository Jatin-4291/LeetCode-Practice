// Last updated: 8/30/2025, 1:21:49 PM
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // Sorting lower-left diagonals (decreasing order)
        int l=n-1;
        for (int i = 0; i < n; i++) {
            vector<int> diagonal;
            int j = i, k = 0;
            while (j < n && k <= l) {
                diagonal.push_back(grid[j][k]);
                j++;
                k++;
            }
            sort(diagonal.rbegin(), diagonal.rend()); // Sort in decreasing order
            
            // Put back sorted values
            j = i, k = 0;
            int index = 0;
            while (j < n && k <= l) {
                grid[j][k] = diagonal[index++];
                j++;
                k++;
            }
            l--;
        }

        // Sorting upper-right diagonals (increasing order)
        l=n-2;
        for (int i = 1; i < n; i++) {
            vector<int> diagonal;
            int j = 0, k = i;
            while (j<=l && k < n) {
                diagonal.push_back(grid[j][k]);
                j++;
                k++;
            }
            sort(diagonal.begin(), diagonal.end()); // Sort in increasing order
            
            // Put back sorted values
            j = 0, k = i;
            int index = 0;
            while (j <= l && k < n) {
                grid[j][k] = diagonal[index++];
                j++;
                k++;
            }
            l--;
        }

        return grid;
    }
};
