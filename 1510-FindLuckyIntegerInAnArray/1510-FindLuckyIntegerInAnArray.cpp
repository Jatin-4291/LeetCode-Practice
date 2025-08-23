// Last updated: 8/23/2025, 2:37:06 PM
class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        int ans=-1;
        for(auto& m:mp){
            auto [key,val]=m;
            if(key==val){
                ans=max(ans,val);
            }
        }
        return ans;

    }
};