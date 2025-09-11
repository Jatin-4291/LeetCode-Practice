// Last updated: 9/11/2025, 11:01:20 PM
class Solution {
public:
    bool dfs(int i,vector<bool>& vis,vector<bool>& visPath,vector<vector<int>>& graph){
        vis[i]=true;
        visPath[i]=true;
        for(auto ngh:graph[i]){
            if(!vis[ngh]){
                if(!dfs(ngh,vis,visPath,graph)) return false;
            }
            else if(visPath[ngh]){
                return false;
            }
        }
         visPath[i] = false;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool> vis(n,false);
        vector<bool> visPath(n,false);
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(dfs(i,vis,visPath,graph)) ans.push_back(i);
        }
        return ans;
    }
};