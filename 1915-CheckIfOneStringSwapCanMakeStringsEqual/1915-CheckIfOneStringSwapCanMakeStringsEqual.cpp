// Last updated: 8/30/2025, 1:24:57 PM
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> diff;
        
        // Identify the differing indices
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                diff.push_back(i);
            }
        }
        
        // If no differences, return true
        if (diff.size() == 0) {
            return true;
        }
        if (diff.size() == 2) {
            swap(s1[diff[0]], s1[diff[1]]);
            return s1 == s2;
        }
        return false;
    }
};
