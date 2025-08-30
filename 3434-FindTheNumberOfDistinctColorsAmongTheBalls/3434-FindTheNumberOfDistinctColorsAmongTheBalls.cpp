// Last updated: 8/30/2025, 1:22:48 PM
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> balls;
        unordered_map<int,int> colors;
        vector<int> ans;
        int count=0;
        for(int i=0;i<queries.size();i++){
            int x=queries[i][0];
            int y=queries[i][1];
            if(balls.find(x)!=balls.end()){
               colors[balls[x]]--;
                if (colors[balls[x]] == 0) {
                    colors.erase(balls[x]);
                    count--;
                }
            }
            colors[y]+=1;
            balls[x]=y;
            if(colors[y]==1){
                count++;
            
            }
            
           
            ans.push_back(count);
        }
        return ans;

    }
};