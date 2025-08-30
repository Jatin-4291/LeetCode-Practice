// Last updated: 8/30/2025, 1:21:21 PM
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        string temp;
        for (int i = 0; i < nums.size(); i++) {
            temp += to_string(nums[i]) + ',';
        }

        vector<vector<int>> x;
        int sum = 0, j = 0;
        for (int i = 0; i < temp.size(); i++) {
            if (isdigit(temp[i])) {
                sum += temp[i] - '0';
            } else {
                x.push_back({sum, nums[j], j});
                sum = 0;
                j++;
            }
        }
        sort(x.begin(), x.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) 
                return a[1] < b[1];
            return a[0] < b[0];
        });

        int n = nums.size();
        vector<bool> visited(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i])
                continue;

            int cycle = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = x[j][2];
                cycle++;
            }

            if (cycle > 1)
                ans += cycle - 1;
        }

        return ans;
    }
};
