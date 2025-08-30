// Last updated: 8/30/2025, 1:21:12 PM
class Solution {
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        int maxi = 0;
        for (auto [key, val] : mp) {
            maxi = max(maxi, val);
        }
        vector<bool> isPrime(maxi + 1, true);
        isPrime[0] = false;
        isPrime[1] = false;

        for (int i = 2; i * i <= maxi; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= maxi; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        for (auto [key, val] : mp) {
            if (isPrime[val]) {
                return true;
            }
        }
        return false;
    }
};