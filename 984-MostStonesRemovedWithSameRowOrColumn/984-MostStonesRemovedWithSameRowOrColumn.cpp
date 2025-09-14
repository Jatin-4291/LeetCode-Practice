// Last updated: 9/14/2025, 10:32:37 PM
class DisJointSet {
public:
    vector<int> rank, parent;

    DisJointSet(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUParent(int u) {
        if (parent[u] == u) return u;
        return parent[u] = findUParent(parent[u]);
    }

    void unionByRank(int u, int v) {
        int pu = findUParent(u);
        int pv = findUParent(v);
        if (pu == pv) return;
        
        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pv] < rank[pu]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        DisJointSet ds(n);
        for(int i=0;i<stones.size();i++){
            for(int j=0;j<n;j++){
            auto xp=stones[i][0];
            auto yp=stones[i][1];
            int x=stones[j][0];
            int y=stones[j][1];
            if(x==xp || y==yp){
                ds.unionByRank(i,j);
            }
            }
        }
        int comp=0;
        for(int i=0;i<n;i++){
            int ult_u=ds.findUParent(i);
            if(ult_u==i) comp++;
        }
        return n-comp;
        
    }
};