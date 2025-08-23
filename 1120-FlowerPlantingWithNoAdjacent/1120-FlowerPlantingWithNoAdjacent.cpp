// Last updated: 8/23/2025, 2:37:16 PM
class Solution {
public:
    bool isPossible(int node, int color, vector<vector<int>>& graph, vector<int>& flower) {
        for (int i = 0; i < graph[node].size(); i++) {
            if (flower[graph[node][i]] == color) {
                return false;
            }
        }
        return true;
    }

    bool solve(int node, int n, vector<vector<int>>& graph, vector<int>& flower) {
        if (node == n) return true;

        for (int color = 1; color <= 4; color++) {
            if (isPossible(node, color, graph, flower)) {
                flower[node] = color;
                if (solve(node + 1, n, graph, flower)) return true;
                flower[node] = 0;
            }
        }
        return false;
    }

    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> graph(n);
        for (int i = 0; i < paths.size(); i++) {
            int e1 = paths[i][0] - 1;
            int e2 = paths[i][1] - 1;
            graph[e1].push_back(e2);
            graph[e2].push_back(e1);
        }

        vector<int> flower(n, 0);
        solve(0, n, graph, flower);
        return flower;
    }
};
