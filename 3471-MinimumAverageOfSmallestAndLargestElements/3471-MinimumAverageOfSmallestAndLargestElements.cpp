// Last updated: 8/30/2025, 1:22:37 PM
class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        vector<double> avg;
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = nums.size() - 1;
        
        while (i <= j) {
            avg.push_back((nums[i] + nums[j]) / 2.0);
            i++;
            j--;
        }
        
        sort(avg.begin(), avg.end());
        return avg[0];
    }
};
