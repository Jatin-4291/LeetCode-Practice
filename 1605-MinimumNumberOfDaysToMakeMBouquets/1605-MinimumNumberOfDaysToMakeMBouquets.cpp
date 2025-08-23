// Last updated: 8/23/2025, 2:36:59 PM
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l=1;
        int h=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(l<=h){
            int mid=(l+h)/2;
            int countBouq=0;
            int countFlower=0;
            for(int i=0;i<bloomDay.size();i++){
                if(bloomDay[i]<=mid){
                    countFlower++;
                    if(countFlower==k){
                    countBouq++;
                    countFlower=0;
                    }
                }
                else{
                    countFlower=0;
                }
            }
            if(countBouq>=m){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};