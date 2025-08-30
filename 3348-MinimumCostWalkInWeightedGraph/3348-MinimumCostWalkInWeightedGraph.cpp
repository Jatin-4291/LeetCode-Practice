// Last updated: 8/30/2025, 1:23:07 PM
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        // Create the adjacency list of the graph
        vector<vector<pair<int, int>>> adjList(n);
        for (const auto& edge : edges) {
            adjList[edge[0]].push_back({edge[1], edge[2]});
            adjList[edge[1]].push_back({edge[0], edge[2]});
        }

        vector<bool> visited(n, false);
        vector<int> components(n, -1);
        vector<int> componentCost;

        int componentId = 0;

        // Perform DFS for each unvisited node to identify components and calculate their costs
        for (int node = 0; node < n; ++node) {
            if (!visited[node]) {
                componentCost.push_back(getComponentCost(node, adjList, visited, components, componentId));
                componentId++;
            }
        }

        vector<int> answer(queries.size(), -1);
        for (size_t i = 0; i < queries.size(); ++i) {
            int start = queries[i][0];
            int end = queries[i][1];

            if (components[start] == components[end]) {
                answer[i] = componentCost[components[start]];
            }
        }

        return answer;
    }

private:
    int getComponentCost(int node, vector<vector<pair<int, int>>>& adjList, vector<bool>& visited, vector<int>& components, int componentId) {
        int currentCost = INT_MAX;
        components[node] = componentId;
        visited[node] = true;

        for (const auto& neighbor : adjList[node]) {
            int weight = neighbor.second;
            currentCost &= weight;

            if (!visited[neighbor.first]) {
                currentCost &= getComponentCost(neighbor.first, adjList, visited, components, componentId);
            }
        }

        return currentCost;
    }
};
