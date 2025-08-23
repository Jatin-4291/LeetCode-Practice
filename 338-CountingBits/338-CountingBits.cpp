// Last updated: 8/23/2025, 2:38:15 PM
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i=0;i<=n;i++){
            int x=i;
            int cnt=0;
            while(x>0){
                x=(x&x-1);
                cnt++;
            }
            ans[i]=cnt;
        }
        return  ans;
    }
};