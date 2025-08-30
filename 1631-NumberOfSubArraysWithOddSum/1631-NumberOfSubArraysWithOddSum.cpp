// Last updated: 8/30/2025, 1:25:14 PM
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int odd_count = 0, even_count = 1;
        int sum = 0, result = 0;
        const int MOD = 1e9 + 7;  

        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (sum % 2 != 0) {
                result = (result + even_count) % MOD; 
                odd_count++; 
            } else {
                result = (result + odd_count) % MOD;
                even_count++;
            }
        }

        return result;
    }
};
