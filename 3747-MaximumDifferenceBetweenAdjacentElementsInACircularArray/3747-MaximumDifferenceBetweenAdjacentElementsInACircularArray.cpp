// Last updated: 8/30/2025, 1:21:50 PM
class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n=nums.size();
        int max=0;
        int i=0;
        while(i<n){
            int temp=abs(nums[i%n]-nums[(i+1)%n]);
            if(temp>max){
                max=temp;
            }
            i++;
        }
        return max;
        
    }
};