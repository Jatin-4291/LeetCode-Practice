// Last updated: 8/23/2025, 2:40:22 PM
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0;
        int h=nums.size()-1;
        int ans=-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]<=target){
                if(nums[mid]==target){
                    return mid;
                }
                l=mid+1;
            }
            else{
                h=mid-1;
            }
            
        }
        return l;
    }
};