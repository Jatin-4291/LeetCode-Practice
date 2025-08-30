// Last updated: 8/30/2025, 1:22:01 PM
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int totalSum = 0;
        int count = 0;
        
        // Calculate total sum of the array
        for (int num : nums) {
            totalSum += num;
        }
        
        int sum1 = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            sum1 += nums[i];
            int sum2 = totalSum - sum1;
            if ((sum1 - sum2) % 2 == 0) {
                count++;
            }
        }
        
        return count;
    }
};
