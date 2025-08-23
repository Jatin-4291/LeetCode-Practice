// Last updated: 8/23/2025, 2:37:32 PM
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        if(piles.size()==h){
            return high;
        }
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            long long count=0;
            for(int i=0;i<piles.size();i++){
                count+=piles[i]/mid;
                if(piles[i]%mid>0){
                    count++;
                };
            } 
            if(count<=h){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;

    }
};