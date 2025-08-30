// Last updated: 8/30/2025, 1:23:03 PM
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
       int j=1;
       int i=0;
       int ans=1;
       int count=1;
       while(j<nums.size()){
        if(nums[i]>nums[j]){
            count++;
            if(count>ans){
                ans=count;
            }
            i++;
            j++;
        }
        else{ 
            count=1;         
            i=j;
            j++;
        }
       }
       j=1;
       i=0;
       count=1;
        while(j<nums.size()){
        if(nums[i]<nums[j]){
            count++;
            if(count>ans){
                ans=count;
            }
            i++;
            j++;
        }
        else{ 
            count=1;        
            i=j;
            j++;
        }
       }
       return ans;
    }
};