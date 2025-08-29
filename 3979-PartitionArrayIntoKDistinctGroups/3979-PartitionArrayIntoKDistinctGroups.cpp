// Last updated: 8/29/2025, 4:29:07 PM
class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        if(nums.size()%k!=0) return false;
        int x=nums.size()/k;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto [key,val]:mp){
            if(val>x) return false;
        }
        return true;
    }
};