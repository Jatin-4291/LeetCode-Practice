// Last updated: 9/8/2025, 11:09:07 PM
class Solution {
public:
    int minOperations(string s) {
        int ans = 0;
        for (char c : s) {
            int dist = (26 - (c - 'a')) % 26;
            ans = max(ans, dist);
        }
        return ans;
    }
};
