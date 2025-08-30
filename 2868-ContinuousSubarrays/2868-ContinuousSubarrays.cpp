// Last updated: 8/30/2025, 1:23:50 PM
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans=0;
        int j=0;
        multiset<int> window;
        for(int i=0;i<nums.size();i++){
            window.insert(nums[i]);
           while (*window.rbegin() - *window.begin() > 2) {
                 window.erase(window.find(nums[j]));
                j++;
           }
           ans += (i - j + 1);

        }
        return ans;
        
    }
};