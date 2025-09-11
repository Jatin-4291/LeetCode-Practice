// Last updated: 9/11/2025, 11:01:25 PM
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> q;
        int n =image.size();
        int m=image[0].size();
        q.push({sr,sc});
        int clr=image[sr][sc];
        if (clr == color) return image;
        vector<vector<int>> directions={{-1,0},{0,-1},{0,1},{1,0}};
        while(!q.empty()){
            auto [i,j]=q.front();
            q.pop();
            image[i][j]=color;
            for(auto dir:directions){
                int nr=i+dir[0];
                int nc=j+dir[1];
                if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc]==clr){
                    q.push({nr,nc});
                }
            }
        }
        return image;
    }
};