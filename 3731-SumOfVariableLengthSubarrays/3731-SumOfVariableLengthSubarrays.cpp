// Last updated: 8/30/2025, 1:21:52 PM
class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n=nums.size();
        int total=0;
        for(int i=0;i<n;i++){
            int start=max(0,i-nums[i]);
            for(int k=start;k<=i;k++){
                total+=nums[k];
            }
        }
        return total;        
    }
};