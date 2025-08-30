// Last updated: 8/30/2025, 1:21:32 PM
class Solution {
public:
    string smallestPalindrome(string s) {
        unordered_map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }

        string left = "", right = "", mid = "";
        for (char c = 'a'; c <= 'z'; c++) {
            if (mp[c] % 2 != 0 && mid.empty()) {
                mid = c;
                mp[c]--;
            }

            int half = mp[c] / 2;
            left += string(half, c);
            right = string(half, c) + right;
        }

        return left + mid + right;
    }
};
