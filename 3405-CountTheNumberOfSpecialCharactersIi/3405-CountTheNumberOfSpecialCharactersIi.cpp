// Last updated: 8/30/2025, 1:22:53 PM
class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int> upper;
        unordered_map<char,int> lower;
        int ans = 0;

        for (int i = 0; i < word.size(); i++) {
            if ('A' <= word[i] && word[i] <= 'Z') {
                if (upper.find(word[i]) == upper.end()) {
                    upper[word[i]] = i;
                }
            }
            if ('a' <= word[i] && word[i] <= 'z') {
                lower[word[i]] = i; // we want last occurrence
            }
        }

        for (auto& it : upper) {
            char upperChar = it.first;
            char lowerChar = upperChar + 32;

            if (lower.count(lowerChar) && lower[lowerChar] < upper[upperChar]) {
                ans++;
            }
        }

        return ans;
    }
};
