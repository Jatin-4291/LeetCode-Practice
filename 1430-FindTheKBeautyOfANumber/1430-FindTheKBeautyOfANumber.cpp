// Last updated: 8/30/2025, 1:25:33 PM
class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int ans = 0;
        for (int i = 0; i <= s.size() - k; i++) {
            string temp = s.substr(i, k);
            int n = stoi(temp);
            if (n != 0 && num % n == 0) {
                ans++;
            }
        }
        
        return ans;
    }
};
