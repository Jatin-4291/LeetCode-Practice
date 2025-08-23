// Last updated: 8/23/2025, 2:36:02 PM
class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        const int MOD = 1e9 + 7;
        unordered_map<int, vector<int>> graph;
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);  // Add both directions for undirected tree
        }

        queue<pair<int, int>> q;
        q.push({1, 0});
        unordered_set<int> visited;
        visited.insert(1);

        int maxLength = 0;

        while (!q.empty()) {
            auto [node, dist] = q.front();
            q.pop();
            maxLength = max(maxLength, dist);
            for (int neighbor : graph[node]) {
                if (!visited.count(neighbor)) {
                    visited.insert(neighbor);
                    q.push({neighbor, dist + 1});
                }
            }
        }

        if (maxLength == 0) return 0;
        long long result = 1;
        int exp = maxLength - 1;
        while (exp > 0) {
            result = (result * 2) % MOD;
            exp--;
        }

        return (int)result;
    }
};
