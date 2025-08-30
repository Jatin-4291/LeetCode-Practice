// Last updated: 8/30/2025, 1:23:45 PM
class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        unordered_map<long long, int> blackCount;
        vector<long long> ans(5, 0);

        for (auto& coord : coordinates) {
            int x = coord[0];
            int y = coord[1];

            for (int dx = -1; dx <= 0; dx++) {
                for (int dy = -1; dy <= 0; dy++) {
                    int i = x + dx;
                    int j = y + dy;
                    if (i >= 0 && j >= 0 && i < m - 1 && j < n - 1) {
                        long long key = 1LL * i * n + j; 
                        blackCount[key]++;
                    }
                }
            }
        }

        long long totalBlocks = 1LL * (m - 1) * (n - 1);
        for (auto& [k, v] : blackCount) {
            ans[v]++;
        }
        ans[0] = totalBlocks - accumulate(ans.begin() + 1, ans.end(), 0LL);
        return ans;
    }
};
