// Last updated: 8/30/2025, 1:24:56 PM
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxi=INT_MIN;
        int sum=0;
        int maxSum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxi){
                maxi=nums[i];
                sum+=nums[i];             
                maxSum=max(maxSum,sum);
            }
            else{
                sum=0;
                sum+=nums[i];
                maxi=nums[i];
            }
             
        }
        return maxSum;
    }
};