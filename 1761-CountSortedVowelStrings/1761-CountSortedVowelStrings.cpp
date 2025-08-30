// Last updated: 8/30/2025, 1:25:06 PM
class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> dp(5, 1); 
        for (int i = 2; i <= n; i++) {
            for (int j = 3; j >= 0; j--) {
                dp[j] += dp[j + 1]; 
            }
        }
        int result = 0;
        for (int i = 0; i < 5; i++) {
            result += dp[i];
        }

        return result;
    }
};
