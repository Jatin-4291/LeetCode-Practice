// Last updated: 8/30/2025, 1:22:23 PM
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> ans(n-k+1,-1);
        
        for (int i = 0; i < n; i++) {
            // If deque is empty, start a new window
            if (dq.empty()) {
                dq.push_back(nums[i]);
            }
            else {
                if (nums[i] == dq.back() + 1) {
                    dq.push_back(nums[i]);
                } else {
                    dq.clear();
                    dq.push_back(nums[i]);
                }
            }
            if (dq.size() == k) {
                cout<<i;
                ans[i-(k-1)]=dq.back();
                dq.pop_front();
            }
        }

        return ans;
    }
};
