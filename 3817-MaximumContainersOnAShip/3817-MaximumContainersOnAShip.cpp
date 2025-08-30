// Last updated: 8/30/2025, 1:21:31 PM
class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        int ans=0;
        for(int i=1;i<=n*n;i++){
            if(w*i<=maxWeight){
                ans=i;
            }
        }
        return ans;
    }
};