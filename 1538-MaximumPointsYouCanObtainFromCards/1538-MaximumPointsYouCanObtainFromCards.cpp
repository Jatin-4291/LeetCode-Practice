// Last updated: 8/23/2025, 2:37:05 PM
class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int j=n-1;
        int sum=0;
        while(i<k){
            sum+=nums[i];
            i++;
        }
        i--;
        int ans=sum;
        while(i>=0 && j>=n-k-1){
            sum-=nums[i];
            sum+=nums[j];
             ans=max(ans,sum);
            j--;
            i--;
        }
        return ans;
    }
};