// Last updated: 8/23/2025, 2:39:42 PM
class Solution {
public:
    void solve(int i,vector<int>& nums,vector<int>& temp,vector<vector<int>>& ans){
        if(i>=nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        solve(i+1,nums,temp,ans);
        temp.pop_back();
        int j=i+1;
        while(j<nums.size() && nums[i]==nums[j]){
            j++;
        }
        solve(j,nums,temp,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        solve(0,nums,temp,ans);
        return ans;
    }
};