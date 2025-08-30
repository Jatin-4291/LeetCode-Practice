// Last updated: 8/30/2025, 1:23:04 PM
class Solution {
public:
    string findLatestTime(string s) {
        if (s[0] == '?') {
            s[0] = (s[1] == '?' || s[1] <= '1') ? '1' : '0'; 
        }
        if (s[1] == '?') {
            s[1] = (s[0] == '0') ? '9' : '1';  // Set max valid hour
        }
        if (s[3] == '?') {
            s[3] = '5';  // Maximize tens place of minutes
        }
        if (s[4] == '?') {
            s[4] = '9';  // Maximize units place of minutes
        }
        return s;
    }
};
