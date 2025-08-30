// Last updated: 8/30/2025, 1:24:29 PM
class Solution {
public:
    bool divideArray(vector<int>& nums) {
       if(nums.size()%2!=0){
        return false;
       }  
       unordered_map<int,int> mp;
       for(int i=0;i<nums.size();i++){
        mp[nums[i]]++;
       }
       for(auto &p:mp){
        if(p.second%2!=0){
            return false;
        }
       }
       return true;
    }
};