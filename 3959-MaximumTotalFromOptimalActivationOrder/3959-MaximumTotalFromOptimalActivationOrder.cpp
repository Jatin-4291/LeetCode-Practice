// Last updated: 8/23/2025, 2:35:23 PM
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxTotal(vector<int>& value, vector<int>& limit) {
        int n = value.size();
        vector<pair<int,int>> vals;
        for (int i = 0; i < n; i++) {
            vals.push_back({value[i], limit[i]});
        }

        // Sort by limit ascending, value descending
        sort(vals.begin(), vals.end(), [](auto &a, auto &b) {
            if (a.second != b.second) return a.second < b.second;
            return a.first > b.first;
        });

        long long score = 0;
        int taken = 0;
        unordered_map<int,int> d;
        unordered_set<int> inactive;

        for (auto &[val, lim] : vals) {
            if (inactive.count(lim)) continue;

            if (lim > taken) {
                score += val;
                d[lim]++;
                taken++;
            }

            if (d[taken] > 0) {
                inactive.insert(taken);
                int num = d[taken];
                d[taken] = 0;
                taken -= num;
            }
        }

        return score;
    }
};
