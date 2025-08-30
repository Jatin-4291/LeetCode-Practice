// Last updated: 8/30/2025, 1:22:30 PM
class Solution {
public:
    int nonSpecialCount(int l, int r) {
        int special = 0;
        int limit = sqrt(r);
        vector<bool> isPrime(limit + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= limit; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= limit; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        for (int i = 2; i <= limit; ++i) {
            if (isPrime[i]) {
                long long square = 1LL * i * i;
                if (square >= l && square <= r) {
                    special++;
                }
            }
        }

        return (r - l + 1) - special;
    }
};
