// Last updated: 8/23/2025, 2:39:28 PM
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        for(int i=1;i<numRows;i++){
            vector<int> row(i + 1, 1);
            for(int j=0;j<=i;j++){
                if(j==0 || j==i){
                    continue;
                } else{
                    row[j]=ans[i-1][j-1]+ans[i-1][j];
                }
            }
            ans.push_back(row);
        }
        return ans;
                
    }
};