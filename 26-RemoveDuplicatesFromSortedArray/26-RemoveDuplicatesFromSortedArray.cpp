// Last updated: 8/23/2025, 2:40:29 PM
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int k=mp.size();
        int j=1;
        for(int i=1;i<k;i++){
            while(nums[j]==nums[j-1]){
                j++;
            }
            nums[i]=nums[j];
            j++;
        }
        return k;
    }
};