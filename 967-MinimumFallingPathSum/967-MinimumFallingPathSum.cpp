// Last updated: 8/29/2025, 4:30:33 PM
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for (int j = 0; j < n; j++) dp[n-1][j] = matrix[n-1][j];

        for (int i = n-2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                int below = matrix[i][j] + dp[i+1][j];
                int left = (j > 0) ? matrix[i][j] + dp[i+1][j-1] : INT_MAX;
                int right = (j < n-1) ? matrix[i][j] + dp[i+1][j+1] : INT_MAX;

                dp[i][j] = min({below, left, right});
            }
        }
        return *min_element(dp[0].begin(), dp[0].end());
    }
};
