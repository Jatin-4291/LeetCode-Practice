// Last updated: 8/30/2025, 1:22:03 PM
class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int i=0;
        int j=i+2;

        int count=0;
        while(i<nums.size()-2){
            if((nums[i]+nums[j])*2==nums[i+1]){
                // cout<<i<<" "<<j;
                count++;
            }
            j++;
            i++;
        }
        return count;
    }
};