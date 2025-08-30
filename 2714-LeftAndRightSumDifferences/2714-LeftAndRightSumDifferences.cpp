// Last updated: 8/30/2025, 1:24:00 PM
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        vector<int> ans;
        int left=0;
        int right=sum;
        for(int i=0;i<nums.size();i++){
            right-=nums[i];
            ans.push_back(abs(left-right));
            left+=nums[i];
        }
        return ans;
    }
};