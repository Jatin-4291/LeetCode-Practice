// Last updated: 8/30/2025, 1:24:32 PM
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> temp;
        int n =nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<pivot){
                temp.push_back(nums[i]);
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]==pivot){
                temp.push_back(nums[i]);
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]>pivot){
                temp.push_back(nums[i]);
            }
        }
        return temp;

    }
  
};