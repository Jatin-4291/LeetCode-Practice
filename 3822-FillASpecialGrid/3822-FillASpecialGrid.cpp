// Last updated: 8/23/2025, 2:36:07 PM
class Solution {
public:
    void solve(pair<int,int> start, int size, int maxDigit, vector<vector<int>>& ans) {
        if (size == 2) {
            ans[start.first][start.second] = maxDigit - 0; 
            ans[start.first + 1][start.second] = maxDigit - 1;
            ans[start.first + 1][start.second + 1] = maxDigit - 2;
            ans[start.first][start.second + 1] = maxDigit - 3;
            return;
        }

        int half = size / 2;
        int blockSize = (size * size) / 4;
        solve({start.first, start.second}, half, maxDigit - 0 * blockSize, ans);
        solve({start.first + half, start.second}, half, maxDigit - 1 * blockSize, ans);
        solve({start.first + half, start.second + half}, half, maxDigit - 2 * blockSize, ans);
        solve({start.first, start.second + half}, half, maxDigit - 3 * blockSize, ans);
    }

    vector<vector<int>> specialGrid(int N) {
        int size = 1 << N;
        if (N==0) {
            return{{0}};
        }
        if(N==1) {
            return {
                {3, 0},
                {2, 1}
            };
        }

        vector<vector<int>> ans(size, vector<int>(size));
        int maxDigit = size * size - 1;
        solve({0, 0}, size, maxDigit, ans);
        return ans;
    }
};
