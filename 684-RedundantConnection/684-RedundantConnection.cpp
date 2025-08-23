// Last updated: 8/23/2025, 2:37:43 PM
class DisjointSet{
    vector<int> parent;
    vector<int> size;
    public:
    DisjointSet(int n){
        parent.resize(n + 1);
    size.resize(n + 1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }   
    }
    int findUparent(int u){
        if(u==parent[u]){
            return u;
        }
        return parent[u]=findUparent(parent[u]);
    }
    bool unionBySize(int u,int v){
        int ult_u=findUparent(u);
        int ult_v=findUparent(v);
        if(ult_u==ult_v) return false;
         if(size[ult_u]<size[ult_v]){
            parent[ult_u]=ult_v;
            size[ult_v]+=size[ult_u];
         }else{
            parent[ult_v]=ult_u;
            size[ult_u]+=size[ult_v];
         }
         return true;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DisjointSet ds(n);
        for(int i=0;i<edges.size();i++){
            if(!ds.unionBySize(edges[i][0],edges[i][1])){
                return edges[i];
            }
        }  
        return {}; 
    }
};