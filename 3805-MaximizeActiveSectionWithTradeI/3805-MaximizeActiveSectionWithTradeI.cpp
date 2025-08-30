// Last updated: 8/30/2025, 1:21:35 PM
class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int maxZeroes = 0;
        int n = s.size();
        int countOne=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                countOne++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {  // Found start of a '1' block
                int leftZeroes = 0, rightZeroes = 0;
                
                // Count zeroes before the block
                int left = i - 1;
                while (left >= 0 && s[left] == '0') {
                    leftZeroes++;
                    left--;
                }
                
                // Count zeroes after the block
                int right = i + 1;
                while (right < n && s[right] == '1') {
                    right++;  // Skip all ones in the block
                }
                while (right < n && s[right] == '0') {
                    rightZeroes++;
                    right++;
                }

                // Update max zeroes
                int total=0;
                if(leftZeroes>0 && rightZeroes>0){
                    
                total=leftZeroes + rightZeroes;
                }
                maxZeroes = max(maxZeroes, total);
                
                // Move `i` to the end of this '1' block
                i = right - 1;
            }
        }
        
        return maxZeroes+countOne;
    }
};
