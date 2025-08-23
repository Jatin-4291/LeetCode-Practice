// Last updated: 8/23/2025, 2:39:26 PM
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxSell=prices[prices.size()-1];
        int ans=INT_MIN;
        for(int i=prices.size()-2;i>=0;i--){
            int profit=maxSell-prices[i];
            ans=max(ans,profit);
            maxSell=max(prices[i],maxSell);
        }
        return ans>0?ans:0;
    }
};