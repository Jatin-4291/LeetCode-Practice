// Last updated: 8/23/2025, 2:35:58 PM
class Solution {
public:
    string resultingString(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (!st.empty()) {
                char top = st.top();
                char curr = s[i];
                int diff = abs(top - curr);
                if (diff == 1 || diff == 25) {
                    st.pop();
                } else {
                    st.push(curr);
                }
            } else {
                st.push(s[i]);
            }
        }

        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
