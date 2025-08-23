// Last updated: 8/23/2025, 2:38:41 PM
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        vector<int> ans;
        for(auto [key,val]:mp){
            if(val>n/3){
                ans.push_back(key);
            }
        }
        return ans;
        
    }
};