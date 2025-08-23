// Last updated: 8/23/2025, 2:37:26 PM
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int MOD = 1e9 + 7;

        vector<int> prev(n), next(n);
        stack<int> st;

        // Previous Less Element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            prev[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }

        // Clear the stack to reuse
        while (!st.empty()) st.pop();

        // Next Less Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            next[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }

        // Total contribution
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            long long contrib = (1LL * arr[i] * prev[i] * next[i]) % MOD;
            sum = (sum + contrib) % MOD;
        }

        return sum;
    }
};
