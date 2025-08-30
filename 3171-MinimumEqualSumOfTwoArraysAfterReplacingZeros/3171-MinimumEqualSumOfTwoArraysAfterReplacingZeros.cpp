// Last updated: 8/30/2025, 1:23:28 PM
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long lSum = 0, rSum = 0;
        int countL0 = 0, countR0 = 0;

        for (int num : nums1) {
            if (num == 0) countL0++;
            else lSum += num;
        }

        for (int num : nums2) {
            if (num == 0) countR0++;
            else rSum += num;
        }

        long long finalSum1 = lSum + countL0;
        long long finalSum2 = rSum + countR0;

        if (finalSum1 == finalSum2) {
            return finalSum1;
        }
        if ((countL0 == 0 && finalSum1 < finalSum2) || 
            (countR0 == 0 && finalSum2 < finalSum1)) {
            return -1;
        }

        return max(finalSum1, finalSum2);
    }
};
