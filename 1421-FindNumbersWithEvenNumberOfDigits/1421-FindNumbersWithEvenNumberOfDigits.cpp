// Last updated: 8/30/2025, 1:25:34 PM
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int count =0;
            while(nums[i]>0){
                count++;
                nums[i]=nums[i]/10;
            }
            if(count%2==0){
                ans++;
            }
        }
        return ans;
    }
};