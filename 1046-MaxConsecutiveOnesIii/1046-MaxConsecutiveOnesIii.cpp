// Last updated: 8/23/2025, 2:37:20 PM
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0;
        int j=0;
      for(int i=0;i<nums.size();i++){
        if(k==0 && nums[i]==0){
            while(k<=0){
                if(nums[j]==0){
                    k++;
                }
                j++;
            }
        }
        if(nums[i]==0 && k>0){
            k--;
        }
        ans=max(ans,i-j+1);
      }
      return ans;  
    }
};