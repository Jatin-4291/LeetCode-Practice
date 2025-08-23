// Last updated: 8/23/2025, 2:36:45 PM
class Solution {
public:
    const int MOD = 1e9 + 7;

    long long modPow(long long base, long long power) {
        long long result = 1;
        base = base % MOD;

        while (power > 0) {
            if (power % 2 == 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            power /= 2;
        }

        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2;
        long long oddCount = n / 2;

        long long ans = (modPow(5, evenCount) * modPow(4, oddCount)) % MOD;
        return (int)ans;
    }
};
