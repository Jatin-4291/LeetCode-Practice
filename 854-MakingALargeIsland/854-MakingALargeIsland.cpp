// Last updated: 9/14/2025, 10:32:46 PM
#include <vector>
#include <unordered_set>
using namespace std;

class DisJointSet {
public:
    vector<int> size, parent;

    DisJointSet(int n) {
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUParent(int u) {
        if (parent[u] == u) return u;
        return parent[u] = findUParent(parent[u]);
    }

    void unionBySize(int u, int v) {
        int pu = findUParent(u);
        int pv = findUParent(v);
        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisJointSet ds(n * n);
        vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        // Step 1: Union all connected 1s
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int id = i * n + j;
                    for (auto &d : dir) {
                        int ni = i + d[0], nj = j + d[1];
                        if (ni >= 0 && nj >= 0 && ni < n && nj < n && grid[ni][nj] == 1) {
                            int nid = ni * n + nj;
                            ds.unionBySize(id, nid);
                        }
                    }
                }
            }
        }

        int maxIsland = 0;
        // Step 2: Try converting each 0 into 1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> uniqueParents;
                    int newSize = 1;
                    for (auto &d : dir) {
                        int ni = i + d[0], nj = j + d[1];
                        if (ni >= 0 && nj >= 0 && ni < n && nj < n && grid[ni][nj] == 1) {
                            int root = ds.findUParent(ni * n + nj);
                            if (uniqueParents.insert(root).second) {
                                newSize += ds.size[root];
                            }
                        }
                    }
                    maxIsland = max(maxIsland, newSize);
                }
            }
        }

        // If there was no 0, whole grid is one big island
        if (maxIsland == 0) maxIsland = n * n;

        return maxIsland;
    }
};
