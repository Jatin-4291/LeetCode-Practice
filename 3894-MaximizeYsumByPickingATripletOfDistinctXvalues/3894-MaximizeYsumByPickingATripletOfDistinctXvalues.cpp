// Last updated: 8/23/2025, 2:35:44 PM
class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        int n = x.size();
        unordered_set<int> usedX;
        vector<pair<int, int>> candidates;

        // Store y[i] with corresponding x[i]
        for (int i = 0; i < n; ++i) {
            candidates.push_back({y[i], x[i]});
        }

        // Sort by y[i] descending (we want max sum)
        sort(candidates.rbegin(), candidates.rend());

        int ans = 0, count = 0;
        for (auto& [valY, valX] : candidates) {
            if (usedX.find(valX) == usedX.end()) {
                ans += valY;
                usedX.insert(valX);
                count++;
                if (count == 3) break;
            }
        }

        return (count < 3) ? -1 : ans;
    }
};
