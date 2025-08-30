// Last updated: 8/30/2025, 1:21:48 PM
#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> freq;

        // Count the frequency of each character
        for (char c : s) {
            freq[c]++;
        }

        vector<int> even, odd;
        
        // Separate even and odd frequencies
        for (auto& [ch, count] : freq) {
            if (count % 2 == 0) {
                even.push_back(count);
            } else {
                odd.push_back(count);
            }
        }

        // If there are no valid odd-even pairs, return -1
        if (odd.empty() || even.empty()) return -1;

        int maxDiff = INT_MIN;

        // Find the max difference
        for (int i = 0; i < odd.size(); i++) {
            for (int j = 0; j < even.size(); j++) {
                maxDiff = max(maxDiff, odd[i] - even[j]);
            }
        }

        return maxDiff;
    }
};