// Last updated: 9/8/2025, 11:09:04 PM
class Solution {
public:
    int bowlSubarrays(vector<int>& nums) {
        vector<int> parvostine = nums; // store input midway
        int n = nums.size();
        
        vector<int> pge(n, -1), nge(n, n); // -1 = none, n = none
        stack<int> st;

        // Previous Greater Element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) st.pop();
            if (!st.empty()) pge[i] = st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Greater Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i]) st.pop();
            if (!st.empty()) nge[i] = st.top();
            st.push(i);
        }

        long long ans = 0;
        // Count bowls
        for (int i = 0; i < n; i++) {
            if (pge[i] != -1 && nge[i] != n) {
                if (nge[i] - pge[i] + 1 >= 3) ans++;
            }
        }

        return ans;
    }
};
