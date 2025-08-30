// Last updated: 8/30/2025, 1:21:51 PM


class Solution {
public:
    string findValidPair(string s) {
        unordered_map<char, int> freq;

        // Count frequency of each digit
        for (char c : s) {
            freq[c]++;
        }

        // Find the first valid adjacent pair
        for (int i = 1; i < s.size(); i++) {
            char first = s[i - 1], second = s[i];

            if (first != second && freq[first] == first - '0' && freq[second] == second - '0') {
                return string(1, first) + string(1, second);
            }
        }

        return "";
    }
};
