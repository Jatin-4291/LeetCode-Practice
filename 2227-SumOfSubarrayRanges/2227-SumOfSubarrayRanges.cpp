// Last updated: 8/23/2025, 2:36:41 PM
class Solution {
public:
    void findNge(vector<int>& nums, vector<int>& nge) {
        int n = nums.size();
        stack<int> st;
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] <= nums[i])
                st.pop();
            nge[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }
    }

    void findPge(vector<int>& nums, vector<int>& pge) {
        int n = nums.size();
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] < nums[i])
                st.pop();
            pge[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }
    }

    void findPse(vector<int>& nums, vector<int>& pse) {
        int n = nums.size();
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] > nums[i])
                st.pop();
            pse[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }
    }

    void findNse(vector<int>& nums, vector<int>& nse) {
        int n = nums.size();
        stack<int> st;
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            nse[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }
    }

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> nse(n), pse(n), nge(n), pge(n);
        findNse(nums, nse);
        findPse(nums, pse);
        findNge(nums, nge);
        findPge(nums, pge);
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            long long maxContri = 1LL * nums[i] * pge[i] * nge[i];
            long long minContri = 1LL * nums[i] * pse[i] * nse[i];
            sum += maxContri - minContri;
        }
        return sum;
    }
};
