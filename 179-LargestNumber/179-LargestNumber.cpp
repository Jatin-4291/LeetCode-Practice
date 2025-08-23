// Last updated: 8/23/2025, 2:38:58 PM
class Solution {
public:
    static bool cmp(int a, int b) {
        string x = to_string(a);
        string y = to_string(b);
        return x + y > y + x; 
    }

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        if (nums[0] == 0) return "0";

        string ans = "";
        for (int num : nums) ans += to_string(num);
        return ans;
    }
};
