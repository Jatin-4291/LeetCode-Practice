// Last updated: 8/30/2025, 1:22:16 PM
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;  // Result array
        for (int num : nums) {
            for (int candidate = 0; candidate <= num; candidate++) {
                if ((candidate | (candidate + 1)) == num) {
                    ans.push_back(candidate);
                    break; 
                }
                if(candidate==num){
                    ans.push_back(-1);
                }
            }
        }
        return ans;
    }
};
