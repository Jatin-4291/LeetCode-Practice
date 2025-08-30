// Last updated: 8/30/2025, 1:25:44 PM
class Solution {
public:
    struct pair_hash {
        size_t operator()(const pair<int, int>& p) const {
            return hash<int>()(p.first) ^ hash<int>()(p.second << 16);
        }
    };

    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<pair<int, int>, int, pair_hash> mp;
        for (int i = 0; i < dominoes.size(); i++) {
            sort(dominoes[i].begin(), dominoes[i].end());
            mp[{dominoes[i][0], dominoes[i][1]}]++;
        }

        int ans = 0;
        for (auto m : mp) {
            int count = m.second;
             ans += count * (count - 1) / 2;
        }

        return ans;
    }
};
