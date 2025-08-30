// Last updated: 8/30/2025, 1:24:23 PM
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int i = 0, count = 0, ans = k; 

        for (int j = 0; j < n; j++) {
            if (blocks[j] == 'W') { 
                count++;
            } 

            if (j - i + 1 == k) { 
                ans = min(ans, count);
                
                if (blocks[i] == 'W') {
                    count--;
                }
                i++;
            }
        }
        
        return ans;
    }
};
