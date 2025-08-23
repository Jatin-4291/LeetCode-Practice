// Last updated: 8/23/2025, 2:37:13 PM
class Solution {
public:
    int solve(vector<int>& nums, int k){
        int r=0;
        int l=0;
        int n=nums.size();
        int sum=0;
        int ans=0;
        while(r<n){
            if(nums[r]%2!=0){
            sum++;
            }
            while(sum>k){
                if(nums[l]%2!=0){
                sum--;
                }
                l++;
            }
            ans+=r-l+1;
            r++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};