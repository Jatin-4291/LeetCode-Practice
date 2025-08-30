// Last updated: 8/30/2025, 1:21:33 PM
class Solution {
public:
    int reverseDegree(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            count += ((26 - (s[i] - 'a')) * (i + 1));  
            
        }
        return count;
    }
};
