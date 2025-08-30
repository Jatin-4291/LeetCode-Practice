// Last updated: 8/30/2025, 1:22:47 PM
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<int, int> freq;
        
        // Multiply elements in nums2 by k and store their frequency
        for (int num : nums2) {
            freq[num * k]++;
        }

        long long ans = 0;

        // Iterate over nums1 and find divisors
        for (int num : nums1) {
            for (int j = 1; j * j <= num; j++) {
                if (num % j == 0) { // j is a divisor of num
                    ans += freq[j];  // Count occurrences of j in nums2
                    
                    // Check the quotient (num / j), avoiding duplicate counting
                    if (j != num / j) {
                        ans += freq[num / j]; 
                    }
                }
            }
        }
        return ans;
    }
};
