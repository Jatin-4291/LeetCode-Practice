// Last updated: 8/30/2025, 1:22:20 PM
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        int vowelPresence[2][128] = {}; // Array to track vowels and their frequency
        vowelPresence[0]['a'] = vowelPresence[0]['e'] = vowelPresence[0]['i'] = vowelPresence[0]['o'] = vowelPresence[0]['u'] = 1;

        long long ans = 0; // Final count of valid substrings
        int c = 0; // Consonant count
        int vowels = 0; // Number of unique vowels in the current window
        int extraLeft = 0, j = 0; // j is the left pointer

        for (int i = 0; i < word.length(); i++) {
            char rightChar = word[i];

            // Check if it's a vowel
            if (vowelPresence[0][rightChar]) {
                if (++vowelPresence[1][rightChar] == 1) vowels++;
            } else {
                c++; // It's a consonant
            }
            while (c > k) {
                char leftChar = word[j++];
                if (vowelPresence[0][leftChar]) {
                    if (--vowelPresence[1][leftChar] == 0) vowels--;
                } else {
                    c--;
                }
                extraLeft = 0;
            }
            while (vowels == 5 && c == k && j < i && vowelPresence[0][word[j]] && vowelPresence[1][word[j]] > 1) {
                extraLeft++;
                vowelPresence[1][word[j++]]--;
            }
            if (c == k && vowels == 5) {
                ans += (1 + extraLeft);
            }
        }

        return ans;
    }
};
