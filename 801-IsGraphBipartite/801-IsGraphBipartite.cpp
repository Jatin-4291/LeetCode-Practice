// Last updated: 9/11/2025, 11:01:22 PM
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,0);
        for(int i=0;i<n;i++){
            queue<pair<int,int>> q;
            if(color[i]==0){
                q.push({i,1});
                color[i]=1;
            }
            while(!q.empty()){
                int size=q.size();
                for(int i=0;i<size;i++){
                    auto [node,clr]=q.front();
                    q.pop();
                    for(auto neighbour:graph[node]){
                        if(color[neighbour]==0){
                            clr==1?q.push({neighbour,2}):q.push({neighbour,1});
                            clr==1?color[neighbour]=2:color[neighbour]=1;
                        }else if(color[neighbour]==clr){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};