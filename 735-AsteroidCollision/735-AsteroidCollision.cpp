// Last updated: 8/23/2025, 2:37:42 PM
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& astroid) {
        stack<int> st;
        for (int i = 0; i < astroid.size(); i++) {
            bool destroyed = false;

            while (!st.empty() && st.top() > 0 && astroid[i] < 0) {
                if (abs(st.top()) < abs(astroid[i])) {
                    st.pop();
                } else if (abs(st.top()) == abs(astroid[i])) {
                    st.pop();
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed) {
                st.push(astroid[i]);
            }
        }
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
