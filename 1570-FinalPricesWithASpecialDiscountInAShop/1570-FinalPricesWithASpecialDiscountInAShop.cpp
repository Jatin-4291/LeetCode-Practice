// Last updated: 8/23/2025, 2:37:00 PM
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> nse(n, 0);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() > prices[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nse[i] = st.top();
            }
            st.push(prices[i]);
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            ans.push_back(prices[i] - nse[i]);
        }

        return ans;
    }
};
