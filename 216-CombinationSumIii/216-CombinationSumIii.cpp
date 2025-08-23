// Last updated: 8/23/2025, 2:38:45 PM
class Solution {
public:
    void solve(int curr, int k, int n, int sum, vector<int>& temp, vector<vector<int>>& ans) {
        if (k == 0) {
            if (sum == n) {
                ans.push_back(temp);
            }
            return;
        }

        if (curr > 9 || sum > n) return; 
        temp.push_back(curr);
        solve(curr + 1, k - 1, n, sum + curr, temp, ans);
        temp.pop_back();
        solve(curr + 1, k, n, sum, temp, ans);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(1, k, n, 0, temp, ans);
        return ans;
    }
};
