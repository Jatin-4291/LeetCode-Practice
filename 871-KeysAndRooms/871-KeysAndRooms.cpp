// Last updated: 8/23/2025, 2:37:36 PM
class Solution {
public:
    void dfs(int i,vector<vector<int>>& rooms,vector<bool>& visited){
        visited[i]=true;
        if(rooms[i].size()==0){
            return;
        }
        for(auto neighbour:rooms[i]){
            if(!visited[neighbour]){
            dfs(neighbour,rooms,visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(),false);
        dfs(0,rooms,visited);
        for(int i=0;i<visited.size();i++){
            if(!visited[i]){
                return false;
            }
        }
        return true;
    }
};