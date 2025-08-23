// Last updated: 8/23/2025, 2:35:32 PM
class Solution {
public:
    typedef long long ll;

    ll minCost(int m, int n, vector<vector<int>>& waitCost) {
        // Directions: down, right
        int dirs[2][2] = {{1, 0}, {0, 1}};

        // Min-heap: {cost, row, col, time}
        priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;

        vector<vector<ll>> minCost(m, vector<ll>(n, LLONG_MAX));
        minCost[0][0] = 1;

        pq.push({1, 0, 0, 1}); // cost, row, col, time

        while (!pq.empty()) {
            auto curr = pq.top(); pq.pop();
            ll cost = curr[0];
            int r = curr[1], c = curr[2], t = curr[3];

            if (r == m - 1 && c == n - 1) return cost;

            ll newCost = cost;
            if (t % 2 == 0) newCost += waitCost[r][c]; // even time = wait

            for (auto& d : dirs) {
                int r_ = r + d[0];
                int c_ = c + d[1];
                if (r_ >= m || c_ >= n) continue;

                ll moveCost = (ll)(r_ + 1) * (c_ + 1);
                ll totalCost = newCost + moveCost;

                if (totalCost < minCost[r_][c_]) {
                    minCost[r_][c_] = totalCost;
                    ll nextTime = t + ((t % 2 == 1) ? 1 : 2); // jump to next odd second
                    pq.push({totalCost, r_, c_, nextTime});
                }
            }
        }

        return -1;
    }
};
