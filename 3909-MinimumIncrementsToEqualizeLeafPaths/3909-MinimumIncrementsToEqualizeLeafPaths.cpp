// Last updated: 8/30/2025, 1:21:10 PM
class Solution {
public:
    int result=0;
    long long dfs(int curr,int parent,vector<vector<int>>& graph,vector<int>& cost){
        vector<long long> child;
        for(auto next:graph[curr]){
            if(next!=parent){
                child.push_back(dfs(next,curr,graph,cost));
            }
        }
        long long maxChild=0;
        if(child.size()>0){
            maxChild=*max_element(child.begin(),child.end());
            for(auto c:child){
                if(c!=maxChild){
                    result++;
                }
            }
        }
        return maxChild+cost[curr];

    }
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        vector<vector<int>> graph(n);
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
             graph[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(0,-1,graph,cost);
        return result;
    }
};
