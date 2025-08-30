// Last updated: 8/30/2025, 1:23:52 PM
class Solution {
public:
    int solve(vector<int>& nums,int k){
        unordered_map<int,int> mp;
        int j=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            while(mp.size()>k){
               mp[nums[j]]--;
                if (mp[nums[j]] == 0) {
                    mp.erase(nums[j]);
                }
                j++;
            }
            ans+=i-j+1;
        }
        return ans;
    }
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int,int> x;
        for(int i=0;i<nums.size();i++){
            x[nums[i]]++;
        }
        int k=x.size();
        int ans=solve(nums,k)-solve(nums,k-1);
        return ans;
    }
};