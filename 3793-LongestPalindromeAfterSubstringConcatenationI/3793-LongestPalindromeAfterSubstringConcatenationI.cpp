// Last updated: 8/30/2025, 1:21:39 PM
class Solution {
public:
    int longestPalindrome(string s, string t) {
        int maxLen = 0;
        string merged = s + t;
        int n = merged.size();

        // Try all substrings from s
        for (int i = 0; i <= s.size(); i++) {
            for (int j = i; j <= s.size(); j++) {
                string subS = s.substr(i, j - i); // Substring from s
                
                // Try all substrings from t
                for (int k = 0; k <= t.size(); k++) {
                    for (int l = k; l <= t.size(); l++) {
                        string subT = t.substr(k, l - k); // Substring from t
                        
                        string combined = subS + subT; // Concatenation
                        if (isPalindrome(combined)) {
                            maxLen = max(maxLen, (int)combined.size());
                        }
                    }
                }
            }
        }
        return maxLen;
    }

private:
    bool isPalindrome(const string& str) {
        int left = 0, right = str.size() - 1;
        while (left < right) {
            if (str[left] != str[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};
