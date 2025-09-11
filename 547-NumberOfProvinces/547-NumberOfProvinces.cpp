// Last updated: 9/11/2025, 11:01:33 PM
class Solution {
public:
    void dfs(int i,vector<vector<int>>& adjList,vector<bool>& vis){
        vis[i]=true;
        for(auto neighbour: adjList[i]){
            if(!vis[neighbour]){
                dfs(neighbour,adjList,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> adjList(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                adjList[i].push_back(j);
                }
            }
        }
        int count=0;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adjList,vis);
                count++;
            }
        }
        return count;
    }
};