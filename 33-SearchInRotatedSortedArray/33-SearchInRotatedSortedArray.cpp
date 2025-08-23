// Last updated: 8/23/2025, 2:40:25 PM
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0;
        int h=n-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]>=nums[l]){
                if(nums[l]<=target && target<=nums[mid]){
                    h=mid-1;
                }
                else{
                    l=mid+1;
                }
            }else{
                if(nums[mid]<=target && target<=nums[h]){
                    l=mid+1;
                }else{
                    h=mid-1;
                }
            }
        }
        return -1;
    }
};
