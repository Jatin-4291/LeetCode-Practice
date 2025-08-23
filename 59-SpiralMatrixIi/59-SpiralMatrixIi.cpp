// Last updated: 8/23/2025, 2:40:04 PM
class Solution {
public:
    void solve(int i, int j, int size, int& count, vector<vector<int>> &x) {
        if (size <= 0) return;
        if (size == 1) {
            x[i][j] = count++;
            return;
        }

        // Top row
        for (int k = 0; k < size - 1; k++) {
            x[i][j + k] = count++;
        }

        // Right column
        for (int k = 0; k < size - 1; k++) {
            x[i + k][j + size - 1] = count++;
        }

        // Bottom row
        for (int k = 0; k < size - 1; k++) {
            x[i + size - 1][j + size - 1 - k] = count++;
        }

        // Left column
        for (int k = 0; k < size - 1; k++) {
            x[i + size - 1 - k][j] = count++;
        }

        // Recur for the next inner layer
        solve(i + 1, j + 1, size - 2, count, x);
    }

    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> x(n, vector<int>(n));
        int count = 1;
        solve(0, 0, n, count, x);
        return x;
    }
};
