// Last updated: 8/30/2025, 1:21:40 PM
#include <vector>
#include <unordered_map>

class Solution {
public:
    int maxSum(std::vector<int>& nums) {
        int n = nums.size();
        std::unordered_map<int, int> mp;
        int num=INT_MIN;
        for(int i=0;i<n;i++){
            num=max(num,nums[i]);
        }
        if(num>0){

        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        int ans = 0;
        for (auto &p : mp) {
            if (p.second >= 1) {
                if(p.first>0){
                ans += p.first;
                }
            }
        }
        return ans;
        }
        else{
            return num;
        }
    }
};
