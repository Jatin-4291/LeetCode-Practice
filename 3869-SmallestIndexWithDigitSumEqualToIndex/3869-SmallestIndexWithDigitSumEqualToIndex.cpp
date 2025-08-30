// Last updated: 8/30/2025, 1:21:19 PM
class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int digit=0;
            while(nums[i]>0){
                digit+=nums[i]%10;
                nums[i]=nums[i]/10;
            }
            if(digit==i){
                ans=min(ans,i);
            }
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};