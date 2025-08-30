// Last updated: 8/30/2025, 1:23:58 PM
class Solution {
public:
    void solve(int& edge, int& vertex, vector<bool>& visited, unordered_map<int, vector<int>>& graph, int i) {
        visited[i] = true;
        vertex++;
        edge += graph[i].size();

        for (int neighbour : graph[i]) {
            if (!visited[neighbour]) {
                solve(edge, vertex, visited, graph, neighbour);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        unordered_map<int, vector<int>> graph;
        int m = edges.size();

        // Build the adjacency list
        for (int i = 0; i < m; i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]); 
        }

        vector<pair<int, int>> ev;
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int edge = 0;
                int vertex = 0;
                solve(edge, vertex, visited, graph, i);
                ev.push_back({vertex, edge / 2}); 
            }
        }

        for (auto& pair : ev) {
            int x = pair.first;   
            int e = pair.second;  
            if ((x * (x - 1)) / 2 == e) {
                ans++;
            }
        }

        return ans;
    }
};