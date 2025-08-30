// Last updated: 8/30/2025, 1:22:25 PM
class Solution {
public:
    int computeMinDist(unordered_map<int, set<int>>& graph, int n, vector<int>& dp) {
        dp[n - 1] = 0;  // Distance from n-1 to n-1 is 0

        for (int i = n - 2; i >= 0; i--) {
            dp[i] = INT_MAX;
            for (int neighbor : graph[i]) {
                if (neighbor < n && dp[neighbor] != INT_MAX) {
                    dp[i] = min(dp[i], 1 + dp[neighbor]);
                }
            }
        }

        return dp[0];
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int, set<int>> graph;
        for (int i = 0; i < n - 1; i++) {
            graph[i].insert(i + 1);
        }

        vector<int> ans;
        for (auto& q : queries) {
            graph[q[0]].insert(q[1]);
            vector<int> dp(n, INT_MAX);
            int dist = computeMinDist(graph, n, dp);
            ans.push_back(dist);
        }

        return ans;
    }
};
