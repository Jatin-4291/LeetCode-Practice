// Last updated: 8/30/2025, 1:22:56 PM
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isSameFrequency(const vector<int>& freq1, const vector<int>& freq2) {
        for (int i = 0; i < 26; ++i) {
            if (freq1[i] != freq2[i]) return false;
        }
        return true;
    }

    int minAnagramLength(string s) {
        int n = s.size();
        vector<int> fullFreq(26, 0);

        // Calculate frequency of entire string
        for (char c : s) {
            fullFreq[c - 'a']++;
        }

        for (int len = 1; len <= n; ++len) {
            if (n % len != 0) continue;  // Only divisors of n

            vector<int> currentFreq(26, 0);
            bool valid = true;
            for (int i = 0; i < len; ++i) {
                currentFreq[s[i] - 'a']++;
            }

            // Now check the frequency of subsequent substrings
            for (int i = len; i < n; i += len) {
                vector<int> tempFreq(26, 0);
                for (int j = i; j < i + len; ++j) {
                    tempFreq[s[j] - 'a']++;
                }

                if (!isSameFrequency(currentFreq, tempFreq)) {
                    valid = false;
                    break;
                }
            }

            if (valid) return len;
        }

        return n;
    }
};
