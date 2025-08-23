// Last updated: 8/23/2025, 2:37:51 PM
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefix;
        int sum=0;
        prefix[0]=1;
        int count=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            count += prefix[sum - k];
            prefix[sum]++;
        }
        return count;
    }
};