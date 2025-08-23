// Last updated: 8/23/2025, 2:40:21 PM
class Solution {
public:
    void solve(int i,int sum,int target,vector<int>& nums,vector<int>& temp,vector<vector<int>>& ans){
        if(i>=nums.size()){
            if(sum==target){
                ans.push_back(temp);
            }
            return;
        }
        if(sum>target) return;
            temp.push_back(nums[i]);
            solve(i,sum+nums[i],target,nums,temp,ans);
            // solve(i+1,sum+nums[i],target,nums,temp,ans);
            temp.pop_back();
            solve(i+1,sum,target,nums,temp,ans);

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        solve(0,0,target,nums,temp,ans);
        return ans;
    }
};