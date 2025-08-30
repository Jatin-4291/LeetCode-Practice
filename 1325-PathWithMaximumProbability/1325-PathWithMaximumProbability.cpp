// Last updated: 8/30/2025, 1:25:39 PM
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        // Step 1: Build graph with edge probabilities
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            double prob = succProb[i];
            graph[u].emplace_back(v, prob);
            graph[v].emplace_back(u, prob);
        }
        queue<pair<int, double>> q;
        q.push({start, 1.0});
        vector<double> maxProb(n, 0.0);
        maxProb[start] = 1.0;
        while (!q.empty()) {
            auto [node, prob] = q.front();
            q.pop();

            for (auto [neigh, edgeProb] : graph[node]) {
                double newProb = prob * edgeProb;
                if (newProb > maxProb[neigh]) {
                    maxProb[neigh] = newProb;
                    q.push({neigh, newProb});
                }
            }
        }

        return maxProb[end];
    }
};
