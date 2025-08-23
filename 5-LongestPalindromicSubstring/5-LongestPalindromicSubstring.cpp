// Last updated: 8/23/2025, 2:40:44 PM
class Solution {
public:
    string longestPalindrome(string s) {
        int len = 0;
        string ans = "";
        int n = s.size();

        for (int i = 0; i < n; i++) {
            int j = i, k = i;
            while (j >= 0 && k < n && s[j] == s[k]) {
                if (k - j + 1 > len) {
                    len = k - j + 1;
                    ans = s.substr(j, len);
                }
                j--;
                k++;
            }

            // Even-length palindrome
            j = i, k = i + 1;
            while (j >= 0 && k < n && s[j] == s[k]) {
                if (k - j + 1 > len) {
                    len = k - j + 1;
                    ans = s.substr(j, len);
                }
                j--;
                k++;
            }
        }

        return ans;
    }
};
