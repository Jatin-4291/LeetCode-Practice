// Last updated: 8/23/2025, 2:40:19 PM
class Solution {
public:
    void solve(int i, int sum, vector<int>& candidates, int target, vector<int>& temp, vector<vector<int>>& ans) {
        if (sum > target) return;
        if (i >= candidates.size()) {
            if (sum == target) {
                ans.push_back(temp);
            }
            return;
        }
        temp.push_back(candidates[i]);
        solve(i + 1, sum + candidates[i], candidates, target, temp, ans);
        temp.pop_back();
        int j = i + 1;
        while (j < candidates.size() && candidates[j] == candidates[i]) {
            j++;
        }
        solve(j, sum, candidates, target, temp, ans); 
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0, 0, candidates, target, temp, ans);
        return ans;
    }
};
