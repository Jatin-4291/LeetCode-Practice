// Last updated: 8/23/2025, 2:35:47 PM
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const int MOD = 1e9 + 7;
        unordered_map<int, vector<int>> yMap;
        for (auto& p : points) {
            yMap[p[1]].push_back(p[0]);
        }
        vector<long long> counts;
        for (auto& [y, row] : yMap) {
            int n = row.size();
            if (n>1) {
                counts.push_back(1LL * n * (n - 1) / 2);
            }
        }
        int ans = 0;
        int prefix=0;
        for (int i = 0; i < counts.size(); ++i) {
            ans=(ans+prefix*counts[i])%MOD;
            prefix=(prefix+counts[i])%MOD;
        }

        return ans;
    }
};
