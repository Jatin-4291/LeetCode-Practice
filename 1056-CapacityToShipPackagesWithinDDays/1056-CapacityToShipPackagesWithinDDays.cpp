// Last updated: 8/23/2025, 2:37:19 PM
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
        }
        int l=*max_element(weights.begin(),weights.end());
        int h=sum;
        int ans=0;
        while(l<=h){
            int mid=(l+h)/2;
            int x=0;
            int count=1;
            for(auto wt:weights){
                if(x+wt>mid){
                    count++;
                    x=wt;
                }else{
                    x+=wt;
                }
                
            }
            if(count<=days){
                h=mid-1;
            }else{
                l=mid+1;
            }

        }
        return l;
        
    }
};