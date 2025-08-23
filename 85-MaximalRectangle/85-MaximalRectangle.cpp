// Last updated: 8/23/2025, 2:39:46 PM
class Solution {
public:
    int solve(vector<int>& temp) {
        stack<int> st;
        int ans = 0;
        int n = temp.size();
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && temp[st.top()] > temp[i]) {
                int el = st.top(); st.pop();
                int pse = st.empty() ? -1 : st.top();
                int nse = i;
                ans = max(ans, temp[el] * (nse - pse - 1));
            }
            st.push(i);
        }
        
        while (!st.empty()) {
            int el = st.top(); st.pop();
            int pse = st.empty() ? -1 : st.top();
            int nse = n;
            ans = max(ans, temp[el] * (nse - pse - 1));
        }
        
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int cols = matrix[0].size();
        vector<int> temp(cols, 0);
        int ans = 0;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < cols; j++) {
                temp[j] = (matrix[i][j] == '1') ? temp[j] + 1 : 0;
            }
            ans = max(ans, solve(temp));
        }

        return ans;
    }
};
