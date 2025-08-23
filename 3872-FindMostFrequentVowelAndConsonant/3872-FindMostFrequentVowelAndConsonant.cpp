// Last updated: 8/23/2025, 2:35:51 PM
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> fq;
        for (char c : s) {
            fq[c]++;
        }

        int maxVowel = 0;
        int maxConsonant = 0;

        for (const auto& [ch, count] : fq) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                maxVowel = max(maxVowel, count);
            } else {
                maxConsonant = max(maxConsonant, count);
            }
        }

        return maxVowel + maxConsonant;
    }
};
