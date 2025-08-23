// Last updated: 8/23/2025, 2:37:49 PM
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> arr=nums;
        sort(arr.begin(),arr.end());
        int j=0;
        int i=0;
        int start=-1;
        int end=-1;
        while(i<nums.size() && j<nums.size()){
            if(nums[i]!=arr[j]){
                if(start==-1){
                start=i;
                }
                end=i;
            }
            i++;
            j++;

        }
        if(end==-1 && start==-1){
            return 0;
        }
        return end-start+1;
    }
};