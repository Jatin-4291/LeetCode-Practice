// Last updated: 8/30/2025, 1:25:16 PM
class Solution {
public:
    int xorOperation(int n, int start) {
        int ans=0;
        for(int i=0;i<n;i++){
            ans=ans^(start+(2*i));
        } 
        return ans;  
    }
};