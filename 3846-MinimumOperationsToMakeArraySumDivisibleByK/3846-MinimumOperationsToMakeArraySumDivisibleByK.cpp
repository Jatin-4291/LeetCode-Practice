// Last updated: 8/30/2025, 1:21:22 PM
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
    int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        return sum%k;
    }
};