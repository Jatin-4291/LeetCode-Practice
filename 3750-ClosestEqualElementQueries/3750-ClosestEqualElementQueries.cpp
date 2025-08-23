// Last updated: 8/23/2025, 2:36:16 PM
class Solution {
public:
    int find(int k, const vector<int>& a) {
        int l = 0, r = a.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (a[mid] == k) return mid;
            else if (a[mid] < k) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }

    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;
        for (int idx : queries) {
            int val = nums[idx];
            vector<int>& indices = mp[val];

            if (indices.size() == 1) {
                ans.push_back(-1);
                continue;
            }

            int pos = find(idx, indices);
            int sz = indices.size();

            int prev = (pos - 1 + sz) % sz;
            int next = (pos + 1) % sz;

            int d1 = min(abs(indices[pos] - indices[prev]), n - abs(indices[pos] - indices[prev]));
            int d2 = min(abs(indices[next] - indices[pos]), n - abs(indices[next] - indices[pos]));

            ans.push_back(min(d1, d2));
        }

        return ans;
    }
};
