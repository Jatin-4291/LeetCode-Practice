// Last updated: 8/23/2025, 2:40:10 PM
class Solution {
public:
    void solve(int n, int m, vector<vector<int>>& matrix, int i, int j, vector<int>& ans) {
        if (n <= 0 || m <= 0) {
            return;
        }

        int a = i;
        int b = j;
        for (int k = b; k < b + m; k++) {
            ans.push_back(matrix[a][k]);
        }
        for (int k = a + 1; k < a + n; k++) {
            ans.push_back(matrix[k][b + m - 1]);
        }
        if (n > 1) {
            for (int k = b + m - 2; k >= b; k--) {
                ans.push_back(matrix[a + n - 1][k]);
            }
        }
        if (m > 1) {
            for (int k = a + n - 2; k > a; k--) {
                ans.push_back(matrix[k][b]);
            }
        }
        solve(n - 2, m - 2, matrix, i + 1, j + 1, ans);
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;
        solve(n, m, matrix, 0, 0, ans);
        return ans;
    }
};
