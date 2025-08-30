// Last updated: 8/30/2025, 1:21:55 PM
class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if((i-k>=0 && nums[i]>nums[i-k]) && i+k>n-1){
                sum+=nums[i];
            }
            if((i+k<=n-1 && nums[i]>nums[i+k]) && i-k<0){
                sum+=nums[i];
            }
            if((i+k<=n-1 && nums[i]>nums[i+k]) && (i-k>=0 && nums[i]>nums[i-k])){
                sum+=nums[i];
            }
        }
        return sum;
    }
};