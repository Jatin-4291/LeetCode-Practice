// Last updated: 8/23/2025, 2:37:57 PM
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(nums.begin(), nums.end());
        arr.insert(arr.end(), nums.begin(), nums.end());

        vector<int> nge(2 * n, -1);
        stack<int> st;

        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!st.empty() && arr[i] >= st.top()) {
                st.pop();
            }
            if (!st.empty()) {
                nge[i] = st.top();
            }
            st.push(arr[i]);
        }
        return vector<int>(nge.begin(), nge.begin() + n);
    }
};
