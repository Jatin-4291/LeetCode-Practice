// Last updated: 8/30/2025, 1:22:27 PM
class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int singleSum=0;
        int doubleSum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<10){
                singleSum+=nums[i];
            }else{
                doubleSum+=nums[i];
            }
        }
        if(singleSum>doubleSum || doubleSum>singleSum){
            return true;
        }
            return false;
        
    }
};