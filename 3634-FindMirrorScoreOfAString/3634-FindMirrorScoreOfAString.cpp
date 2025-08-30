// Last updated: 8/30/2025, 1:22:09 PM
#include <vector>
#include <deque>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long calculateScore(string s) {
        unordered_map<char, deque<int>> unmarked_indices; // Track all unmarked indices for each character
        long long score = 0;

        for (int i = 0; i < s.size(); i++) {
            char mirror = 'z' - (s[i] - 'a'); // Calculate the mirror character

            if (!unmarked_indices[mirror].empty()) {
                // Find the closest index
                int closest_index = unmarked_indices[mirror].back();
                unmarked_indices[mirror].pop_back(); // Remove the closest unmarked index
                score += (i - closest_index);
            } else {
                // No valid mirror found, store the current index
                unmarked_indices[s[i]].push_back(i);
            }
        }

        return score;
    }
};
