// Last updated: 8/30/2025, 1:22:13 PM
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int ans=0;
        for(auto m:mp){
            auto [key,v]=m;
            if(key<k){
                return -1;
            }
            if(key>k){
                ans++;
            }
        }
        return ans;
    }
};