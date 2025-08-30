// Last updated: 8/30/2025, 1:23:47 PM
class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= n; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        vector<vector<int>> ans;
        for (int i = 2; i <= n / 2; ++i) {
            if (isPrime[i] && isPrime[n - i]) {
                ans.push_back({i, n - i});
            }
        }
        return ans;
    }
};
