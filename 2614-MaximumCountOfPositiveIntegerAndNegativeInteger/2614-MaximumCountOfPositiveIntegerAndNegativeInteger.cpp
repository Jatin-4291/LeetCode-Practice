// Last updated: 8/30/2025, 1:24:09 PM
class Solution {
public:
    int binarySearch(vector<int>& nums, int target){
        int left=0;
        int right=nums.size()-1;
        int ans=nums.size();
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]<target){
                left=mid+1;
            }
            else{
                ans=mid;
                right=mid-1;
                
            }
        }
        return ans;

    }
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        int negative=binarySearch(nums,0);
        int postive=n-binarySearch(nums,1);
        return  max(postive,negative);
    }
};