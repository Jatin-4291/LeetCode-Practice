// Last updated: 8/30/2025, 1:24:07 PM
class Solution {
public:
    long long coloredCells(int n) {
        long long ans=0;
       for(int i=1;i<=n;i++){
        if(i==1){
            ans+=1;
        }
        else{
            ans+=(i-1)*4;
        }
       }
       return ans;
    }
};