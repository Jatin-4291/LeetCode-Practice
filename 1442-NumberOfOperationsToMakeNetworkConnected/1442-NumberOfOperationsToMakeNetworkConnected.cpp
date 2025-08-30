// Last updated: 8/30/2025, 1:25:31 PM
class DisJointSet {
    vector<int> size;
    vector<int> parent;

public:
    DisJointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUParent(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUParent(parent[node]); // Path compression
    }

    void unionBySize(int u, int v) {
        int ult_u = findUParent(u);
        int ult_v = findUParent(v);
        if (ult_u == ult_v) return;

        if (size[ult_u] < size[ult_v]) {
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        } else {
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) {
            return -1;
        }

        DisJointSet ds(n);
        int components = n;

        for (auto& conn : connections) {
            int u = conn[0];
            int v = conn[1];
            if (ds.findUParent(u) != ds.findUParent(v)) {
                ds.unionBySize(u, v);
                components--;
            }
        }

        return components - 1;
    }
};
