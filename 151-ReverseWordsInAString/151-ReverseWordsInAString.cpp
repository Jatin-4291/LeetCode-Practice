// Last updated: 8/23/2025, 2:39:08 PM
class Solution {
public:
    string reverseWords(string s) {
        int i = s.size() - 1;
        int j = s.size() - 1;
        string ans = "";
        
        while (j >= 0 && i >= 0) {
            if (s[j] == ' ') {
                if (j + 1 <= i) {
                    for (int k = j + 1; k <= i; k++) {
                        ans += s[k];
                    }
                    ans += ' ';
                }
                while (j >= 0 && s[j] == ' ') {
                    j--;
                }
                i = j;
            } else {
                while (j >= 0 && s[j] != ' ') {
                    j--;
                }
            }
        }
        if (j + 1 <= i) {
            for (int k = j + 1; k <= i; k++) {
                ans += s[k];
            }
        }
        if (!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }

        return ans;
    }
};
