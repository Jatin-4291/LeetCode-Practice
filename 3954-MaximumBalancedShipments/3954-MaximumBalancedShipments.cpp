// Last updated: 8/23/2025, 2:35:25 PM
class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int maxWeight=0;
        int n=weight.size();
        int ans=0;
        for(int i=0;i<n;i++){
            maxWeight=max(maxWeight,weight[i]);
            if(maxWeight>weight[i]){
                ans++;
                maxWeight=0;
            }
        }
        return ans;
    }
};