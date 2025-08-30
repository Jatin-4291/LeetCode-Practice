// Last updated: 8/30/2025, 1:22:50 PM
class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if((nums[i]%2==0 && nums[i+1]%2==0)||(nums[i]%2!=0 && nums[i+1]&2!=0)){
                return false;
            }
        }
        return true;
    }
};