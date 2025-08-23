// Last updated: 8/23/2025, 2:37:21 PM
class Solution {
public:
    int solve(vector<int>& nums, int k){
        unordered_map<int,int> mp;
        int r=0;
        int l=0;
        int n=nums.size();
        int sum=0;
        while(r<n){
            mp[nums[r]]++;
            while(mp.size() > k){
                mp[nums[l]]--;
                if(mp[nums[l]] == 0)
                    mp.erase(nums[l]);
                l++;
            }
            sum += (r - l + 1);
            r++;
        }
        return sum;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};
