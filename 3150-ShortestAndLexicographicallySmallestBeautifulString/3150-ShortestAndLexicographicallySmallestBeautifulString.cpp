// Last updated: 8/30/2025, 1:23:34 PM
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int j = 0;
        int count = 0;
        string ans = "";
        int diff = INT_MAX;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                count++;
            }

            // Shrink while count >= k
            while (count >= k) {
                if (count == k) {
                    string candidate = s.substr(j, i - j + 1);
                    if ((int)candidate.size() < diff || 
                        ((int)candidate.size() == diff && candidate < ans)) {
                        ans = candidate;
                        diff = candidate.size();
                    }
                }

                if (s[j] == '1') {
                    count--;
                }
                j++;
            }
        }

        return ans;
    }
};
