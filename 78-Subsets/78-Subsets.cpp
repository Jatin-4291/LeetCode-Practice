// Last updated: 8/23/2025, 2:39:51 PM
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        int subsets=1<<n;
        vector<vector<int>> ans;
        for(int i=0;i<subsets;i++){
            vector<int> temp;
            for(int j=0;j<nums.size();j++){
                if(i&(1<<j)){
                    temp.push_back(nums[j]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
