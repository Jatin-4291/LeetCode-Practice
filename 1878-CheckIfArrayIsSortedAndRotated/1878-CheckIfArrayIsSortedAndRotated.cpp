// Last updated: 8/23/2025, 2:36:51 PM
class Solution {
public:
    bool check(vector<int>& nums) {
    int n = nums.size();
    int count = 0;
    for(int i = 1; i < n; i++) {
        if(nums[i] < nums[i - 1])
            count++;
    }

    if(nums[n - 1] > nums[0])
        count++;
    return count > 1 ? false : true;
}
};