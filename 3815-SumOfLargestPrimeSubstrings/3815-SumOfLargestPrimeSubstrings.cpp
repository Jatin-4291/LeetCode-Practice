// Last updated: 8/23/2025, 2:36:09 PM
class Solution {
public:
    bool isPrime(long long num) {
        if (num < 2) return false;
        for (long long i = 2; i * i <= num; i++) {
            if (num % i == 0) return false;
        }
        return true;
    }

    long long sumOfLargestPrimes(string s) {
        unordered_set<long long> prime;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            long long num = 0;
            for (int j = i; j < n; j++) {
                num = num * 10 + (s[j] - '0');
                if (isPrime(num)) {
                    prime.insert(num);
                }
            }
        }

        vector<long long> primeList(prime.begin(), prime.end());
        sort(primeList.rbegin(), primeList.rend());

        long long ans = 0;
        for (int i = 0; i < min(3, (int)primeList.size()); i++) {
            ans += primeList[i];
        }
        return ans;
    }
};
