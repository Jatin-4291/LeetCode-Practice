// Last updated: 8/23/2025, 2:40:30 PM
class Solution {
public:
    void solve(int open, int close, string temp, vector<string>& ans) {
        if (open == 0 && close == 0) {
            ans.push_back(temp);
            return;
        }

        if (open > 0) {
            solve(open - 1, close, temp + '(', ans);
        }

        if (close > open) { 
            solve(open, close - 1, temp + ')', ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n, n, "", ans);
        return ans;
    }
};
