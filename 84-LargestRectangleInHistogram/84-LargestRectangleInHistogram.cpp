// Last updated: 8/23/2025, 2:39:48 PM
class Solution {
public:
    void findPse(vector<int>& pse, vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }

    void findNse(vector<int>& nse, vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse(n);
        vector<int> pse(n);
        findNse(nse, heights);
        findPse(pse, heights);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int width = nse[i] - pse[i] - 1;
            int area = width * heights[i];
            ans = max(ans, area);
        }
        return ans;
    }
};
