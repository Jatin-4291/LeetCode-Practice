// Last updated: 8/30/2025, 1:22:24 PM
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        for(int i = 0; i <= n - k; i++) {
            bool nonDecreasing = true;
            for(int j = i + 1; j < i + k; j++) {
                if(nums[j-1] != nums[j]-1) {
                    nonDecreasing = false;
                    break;
                }
            }
            if(nonDecreasing)
                ans.push_back(nums[i + k - 1]);
            else
                ans.push_back(-1);
        }
        return ans;
    }
};
