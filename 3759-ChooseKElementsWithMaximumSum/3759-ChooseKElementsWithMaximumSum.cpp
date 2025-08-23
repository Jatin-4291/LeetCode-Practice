// Last updated: 8/23/2025, 2:36:15 PM
class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<tuple<int, int, int>> combined;

        for (int i = 0; i < n; i++) {
            combined.push_back({nums1[i], nums2[i], i});
        }

        sort(combined.begin(), combined.end());

        vector<long long> ans(n, 0);
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long heapSum = 0;
        int prev = 0;

        for (int i = 0; i < n; i++) {
            auto [curr_val, curr_num2, curr_idx] = combined[i];

            // Insert previous nums2[j] into heap where nums1[j] < nums1[i]
            while (prev < i && get<0>(combined[prev]) < curr_val) {
                int val = get<1>(combined[prev]);
                minHeap.push(val);
                heapSum += val;
                if (minHeap.size() > k) {
                    heapSum -= minHeap.top();
                    minHeap.pop();
                }
                prev++;
            }

            // At this point heap has best k nums2[j] where nums1[j] < curr_val
            ans[curr_idx] = heapSum;
        }

        return ans;
    }
};
