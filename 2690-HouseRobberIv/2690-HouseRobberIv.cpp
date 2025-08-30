// Last updated: 8/30/2025, 1:24:02 PM
class Solution {
public:
    bool solve(int mid,vector<int>& nums,int k){
        int i=0;
        int c=0;
        while(i<nums.size()){
            if(nums[i]<=mid){
                c++;
                i++;
            }
            i++;
        }
        return c>=k;
    }
    int minCapability(vector<int>& nums, int k) {
        int n=nums.size();
        int low=INT_MAX;
        for(int i=0;i<n;i++){
            low=min(low,nums[i]);
        }
        int high=INT_MIN;
        for(int i=0;i<n;i++){
            high=max(high,nums[i]);
        }
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(solve(mid,nums,k)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};