// Last updated: 8/30/2025, 1:25:23 PM
class Solution {
public:
    void solve(int i, int n, int k, string& temp, string& ans, int& count) {
        if (i == n) {
            count++;
            if (count == k) {
                ans = temp;
                return;
            }
            return;
        }
        for (int j = 0; j < 3; j++) {
            if (!temp.empty() && temp.back() == 'a' + j) continue;
            
            temp.push_back('a' + j); 
            solve(i + 1, n, k, temp, ans, count); 
            if (!ans.empty()) return; 
            temp.pop_back(); 
        }
    }

    string getHappyString(int n, int k) {
        int count = 0; 
        string temp;
        string ans;
        
        solve(0, n, k, temp, ans, count);  
        return ans;
    }
};
