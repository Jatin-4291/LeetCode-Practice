// Last updated: 8/30/2025, 1:24:24 PM
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool solve(string& pattern, string& ans, int i, int j, unordered_map<int, bool>& isUsed) {
        if (j == pattern.size()) {
            return true;  // Successfully formed a valid sequence
        }
        if (i > 9 || i == 0) {
            return false; // Out of bounds
        }

        if (pattern[j] == 'I') {
            for (int k = i + 1; k <= 9; k++) {
                if (isUsed[k]) continue;
                
                ans += to_string(k);
                isUsed[k] = true;

                if (solve(pattern, ans, k, j + 1, isUsed)) {
                    return true;  // Found valid sequence
                }

                // Backtracking
                ans.pop_back();
                isUsed[k] = false;
            }
        } 
        else if (pattern[j] == 'D') {  // FIXED: Corrected the 'D' condition
            for (int k = i - 1; k > 0; k--) {
                if (isUsed[k]) continue;
                
                ans += to_string(k);
                isUsed[k] = true;

                if (solve(pattern, ans, k, j + 1, isUsed)) {
                    return true;
                }

                // Backtracking
                ans.pop_back();
                isUsed[k] = false;
            }
        }
        return false;
    }

    string smallestNumber(string pattern) {
        string ans = "";
        unordered_map<int, bool> isUsed;

        for (int i = 1; i <= 9; i++) {
            ans += to_string(i);
            isUsed[i] = true;

            if (solve(pattern, ans, i, 0, isUsed)) {
                return ans;  // Return immediately when the smallest number is found
            }

            ans.pop_back();
            isUsed[i] = false;
        }
        return "";
    }
};
