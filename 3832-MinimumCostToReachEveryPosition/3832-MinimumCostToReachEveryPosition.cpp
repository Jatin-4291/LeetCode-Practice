// Last updated: 8/30/2025, 1:21:26 PM
class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        int m=INT_MAX;
        vector<int> ans;
        for(int i=0;i<cost.size();i++){
            if(cost[i]<m){
                m=cost[i];
            }
            ans.push_back(m);
        }
        return ans;
        
    }
};