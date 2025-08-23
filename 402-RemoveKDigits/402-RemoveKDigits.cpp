// Last updated: 8/23/2025, 2:38:13 PM
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for (char c : num) {
            while (!st.empty() && k > 0 && st.top() > c) {
                st.pop();
                k--;
            }
            st.push(c);
        }

        // Remove remaining digits from the end if k > 0
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        // Build the answer
        string ans;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        int i = 0;
        while (i < ans.size() && ans[i] == '0') i++;
        ans = ans.substr(i);

        return ans.empty() ? "0" : ans;
    }
};
