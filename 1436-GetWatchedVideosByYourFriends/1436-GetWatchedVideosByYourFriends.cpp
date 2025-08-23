// Last updated: 8/23/2025, 2:37:10 PM
class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        queue<pair<int,int>> q;
        q.push({id,0});
        vector<bool> visited(friends.size(),false);
        vector<int> temp;
        visited[id]=true;
        while(!q.empty()){
            auto [id,lvl]=q.front();
            if(lvl==level){
               temp.push_back(id);
            }
            q.pop();
            for(auto neighbour:friends[id]){
                if(!visited[neighbour]){
                     visited[neighbour]=true;
                    q.push({neighbour,lvl+1});
                }
            }
        }
        unordered_map<string,int> mp;
        for(auto node:temp){
            for(auto f:watchedVideos[node]){
                mp[f]++;
            }
        }
        vector<pair<int,string>> x;
        for(auto& it: mp){
            auto [key,val]=it;
            x.push_back({val,key});
        }
        sort(x.begin(),x.end());
        vector<string> ans;
        for(auto ch: x){
            auto [cha,len]=ch;
            ans.push_back(len);
        }
        return ans;
    }
};