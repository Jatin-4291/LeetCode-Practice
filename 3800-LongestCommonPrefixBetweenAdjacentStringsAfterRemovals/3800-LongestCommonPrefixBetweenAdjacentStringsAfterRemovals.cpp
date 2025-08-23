// Last updated: 8/23/2025, 2:36:12 PM
class Solution {
public:
    vector<int> longestCommonPrefix(vector<string>& words) {
        int n = words.size();
        vector<int> ans(n, 0);
        if (n < 2) return ans;

        vector<int> a(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            int x = min(words[i].size(), words[i + 1].size());
            int j = 0;
            while (j < x && words[i][j] == words[i + 1][j]) {
                ++j;
            }
            a[i] = j;
        }

        vector<int> pre(n - 1), suf(n - 1);
        pre[0] = a[0];
        for (int i = 1; i < n - 1; ++i) {
            pre[i] = max(pre[i - 1], a[i]);
        }

        suf[n - 2] = a[n - 2];
        for (int i = n - 3; i >= 0; --i) {
            suf[i] = max(suf[i + 1], a[i]);
        }

        for (int skip = 0; skip < n; ++skip) {
            int maxi = 0;
            if (skip >= 2) maxi = max(maxi, pre[skip - 2]);
            if (skip + 1 < n - 1) maxi = max(maxi, suf[skip + 1]);
            if (skip > 0 && skip < n - 1) {
                int len = min(words[skip - 1].size(), words[skip + 1].size());
                int j = 0;
                while (j < len && words[skip - 1][j] == words[skip + 1][j]) {
                    ++j;
                }
                maxi = max(maxi, j);
            }
            ans[skip] = maxi;
        }

        return ans;
    }
};
