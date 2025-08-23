// Last updated: 8/23/2025, 2:35:48 PM
class DisjointSet {
public:
    vector<int> parent;

    DisjointSet(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);  // Path compression
        return parent[x];
    }

    void unite(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu != pv)
            parent[pu] = pv;
    }

    int countComponents() {
        unordered_set<int> roots;
        for (int i = 0; i < parent.size(); ++i)
            roots.insert(find(i));
        return roots.size();
    }
};

class Solution {
public:
    bool canFormKComponents(int maxEdgeWeight, int n, vector<vector<int>>& edges, int k) {
        DisjointSet dsu(n);

        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            if (w <= maxEdgeWeight)
                dsu.unite(u, v);
        }

        return dsu.countComponents() <= k;
    }

    int minCost(int n, vector<vector<int>>& edges, int k) {
        int left = 0, right = 0;
        for (auto& edge : edges)
            right = max(right, edge[2]);

        int answer = right;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (canFormKComponents(mid, n, edges, k)) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return answer;
    }
};
