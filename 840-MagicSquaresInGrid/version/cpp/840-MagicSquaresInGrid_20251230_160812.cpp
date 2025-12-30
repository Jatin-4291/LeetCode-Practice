// Last updated: 12/30/2025, 4:08:12 PM
1class Solution {
2public:
3    bool isMagicMatrix(int r,int c,vector<vector<int>>& grid){
4        int sum = grid[r][c] + grid[r][c+1] + grid[r][c+2];
5        unordered_set<int> st;
6        for(int i=0;i<3;i++){
7            for(int j=0;j<3;j++){
8                int num = grid[r+i][c+j];
9                if(num < 1 || num > 9 || st.count(num)) return false;
10                st.insert(num);
11            }
12        }
13
14        for(int i=0;i<3;i++){
15            if(grid[r][c+i]+grid[r+1][c+i]+grid[r+2][c+i]!=sum || grid[r+i][c]+grid[r+i][c+1]+grid[r+i][c+2]!=sum ) return false;
16        }
17         if(grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2] != sum) return false;
18        if(grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c] != sum) return false;
19
20        return true;
21
22
23    }
24    int numMagicSquaresInside(vector<vector<int>>& grid) {
25        if(grid.size()<3 || grid[0].size()<3) return 0;
26        int n=grid.size();
27        int m=grid[0].size();
28        int ans=0;
29        for(int i=0;i<=n-3;i++){
30            for(int j=0;j<=m-3;j++){
31                if(isMagicMatrix(i,j,grid)) ans++;
32            }
33        }
34        return ans;
35    }
36};