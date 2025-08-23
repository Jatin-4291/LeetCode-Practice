// Last updated: 8/23/2025, 2:39:58 PM
class Solution {
public:
    int climbStairs(int n) {
        int step1=1;
        int step2=0;
        int ans=0;
        for(int i=n-1;i>=0;i--){
            ans=step1+step2;
            step2=step1;
            step1=ans;
        }
        return ans;
    }
};