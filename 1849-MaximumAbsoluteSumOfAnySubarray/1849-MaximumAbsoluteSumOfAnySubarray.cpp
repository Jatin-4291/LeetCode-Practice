// Last updated: 8/30/2025, 1:25:02 PM
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxEnding = 0, minEnding = 0, res = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            maxEnding = max(0, maxEnding + nums[i]);
            minEnding = min(0, minEnding + nums[i]);
            res = max(res, max(abs(maxEnding), abs(minEnding)));
        }   
        
        return res;
    }
};
