// Last updated: 8/30/2025, 1:23:10 PM
class Solution {
public:
    int minOperations(int k) {
        if (k == 1) return 0;

        int ans = k;  
        for (int i = 1; i * i <= k; i++) {  
            int steps = (i - 1) + (k + i - 1) / i - 1;  
            ans = min(ans, steps);  
        }
        return ans;
    }
};
