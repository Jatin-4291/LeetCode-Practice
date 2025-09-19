// Last updated: 9/19/2025, 5:26:04 PM
class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=nums.size()-1;
        vector<int> ans;
        while(i>=0 && k>0){
            int prev=nums[i];
            ans.push_back(prev);
            k--;
            while(i>=0 &&nums[i]==prev){
                i--;
            }
        }
        return ans;
    }
};