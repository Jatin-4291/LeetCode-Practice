// Last updated: 8/30/2025, 1:22:35 PM
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count=0;
        for(int i=0;i<=nums.size()-3;i++){
            if(nums[i]==0){
                for(int j=i;j<i+3;j++){
                    if(nums[j]==0){
                        nums[j]=1;
                    }else{
                        nums[j]=0;
                    }
                }
                count++;
            }
        }   
        int n=nums.size();
        if(nums[n-1]==0 || nums[n-2]==0){
            return -1;
        }
        return count;
    }
};