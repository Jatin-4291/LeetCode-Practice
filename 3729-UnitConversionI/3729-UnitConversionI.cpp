// Last updated: 8/30/2025, 1:21:54 PM
class Solution {
public:
    const int MOD = 1e9 + 7;
    
    void dfs(int node, vector<vector<pair<int, int>>>& graph, vector<int>& value, int prod) {
        value[node] = prod; // set value for this node

        for (auto& [nextNode, weight] : graph[node]) {
            if (value[nextNode] == -1) { // if not visited
                dfs(nextNode, graph, value, (1LL * prod * weight) % MOD);
            }
        }
    }
    
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        int maxNode = 0;
        for (auto& conv : conversions) {
            maxNode = max({maxNode, conv[0], conv[1]});
        }
        
        vector<vector<pair<int, int>>> graph(maxNode + 1);
        
        for (auto& conv : conversions) {
            graph[conv[0]].push_back({conv[1], conv[2]});
        }
        
        vector<int> value(maxNode + 1, -1);
        
        dfs(0, graph, value, 1);
        
        return value;
    }
};
