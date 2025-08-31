// Last updated: 8/31/2025, 8:15:38 PM
class Solution {
public:
    int solve(int i,int j,string& s,vector<vector<int>>& dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==s[j]){
            if(i==j){
                return dp[i][j] = 1 + solve(i+1,j-1,s,dp);
            } else {
                return dp[i][j] = 2 + solve(i+1,j-1,s,dp);
            }
        }

        int skip1 = solve(i+1,j,s,dp);
        int skip2 = solve(i,j-1,s,dp);

        return dp[i][j] = max(skip1, skip2);
    }
int longestPalindromeSubseq(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = n - 1; i >= 0; i--) {
        dp[i][i] = 1;
        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j]) {
                dp[i][j] = 2 + (i + 1 <= j - 1 ? dp[i+1][j-1] : 0);
            } else {
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
    }
    return dp[0][n-1];
}

};
