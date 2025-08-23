// Last updated: 8/23/2025, 2:39:52 PM
class Solution {
public:
    string minWindow(string s, string t) {
        int r = 0, l = 0;
        unordered_map<char, int> mp;
        int sSize = s.size();
        int tSize = t.size();

        // Count frequency of characters in t
        for (int i = 0; i < tSize; i++) {
            mp[t[i]]++;
        }

        int count = 0;
        int minLen = INT_MAX;
        int sIndex = -1;

        while (r < sSize) {
            // Decrease the count from map
            if (mp[s[r]] > 0) {
                count++;
            }
            mp[s[r]]--;
            while (count == tSize) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    sIndex = l;
                }
                mp[s[l]]++;
                if (mp[s[l]] > 0) {
                    count--;
                }
                l++;
            }
            r++;
        }

        if (sIndex == -1) return "";
        return s.substr(sIndex, minLen);
    }
};
