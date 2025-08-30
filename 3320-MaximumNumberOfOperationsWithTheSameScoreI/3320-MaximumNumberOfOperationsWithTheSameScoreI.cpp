// Last updated: 8/30/2025, 1:23:12 PM
class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=1;
        int count=0;
        int prevSum=nums[0]+nums[1];
        while(i<n && j<n){
            int sum=nums[i]+nums[j];
            if(sum==prevSum){
                count++;
            }
            else{
                break;
            }
            i+=2;
            j+=2;
        }
        return count;
    }
};