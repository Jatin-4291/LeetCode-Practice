// Last updated: 8/30/2025, 1:24:15 PM
class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int k=1;k<nums.size();k++){
            if(nums[k]==nums[k-1]){
                nums[k-1]=2*nums[k-1];
                nums[k]=0;
            }
        }
        int pos=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                 swap(nums[i], nums[pos]);
                pos++;
            }
        }
        return nums;
        

    }
};