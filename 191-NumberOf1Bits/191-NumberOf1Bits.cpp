// Last updated: 8/23/2025, 2:38:54 PM
class Solution {
public:
    int hammingWeight(int n) {
        int cnt=0;
        while(n>0){
            n=(n&n-1);
            cnt++;
        }
        return cnt;
    }
};