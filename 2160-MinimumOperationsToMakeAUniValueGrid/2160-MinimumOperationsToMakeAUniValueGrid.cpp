// Last updated: 8/30/2025, 1:24:43 PM
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> temp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                temp.push_back(grid[i][j]);
            }
        }
    
        sort(temp.begin(), temp.end());
        int remainder = temp[0] % x;
        for (int i = 1; i < temp.size(); i++) {
            if (temp[i] % x != remainder) {
                return -1;  
            }
        }
        int median = temp[temp.size() / 2];
        int ans = 0;
        for (int i = 0; i < temp.size(); i++) {
            ans += abs(temp[i] - median) / x;
        }
        
        return ans;
    }
};
