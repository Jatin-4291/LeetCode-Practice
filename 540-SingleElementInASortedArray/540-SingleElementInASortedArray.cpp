// Last updated: 8/23/2025, 2:37:54 PM
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int h = nums.size() - 1;
        int n = nums.size();

        while (l < h) {
            int mid = l + (h - l) / 2;
            if ((mid == 0 || nums[mid] != nums[mid - 1]) &&
                (mid == n - 1 || nums[mid] != nums[mid + 1])) {
                return nums[mid];
            }
            if (mid > 0 && nums[mid] == nums[mid - 1]) {
                int leftCount = mid - 1 - l;
                if (leftCount % 2 == 0) {
                    l = mid + 1;
                } else {
                    h = mid - 2;
                }
            }
            else if (mid < n - 1 && nums[mid] == nums[mid + 1]) {
                int rightCount = h - (mid);
                if (rightCount % 2 == 0) {
                    l = mid + 2;
                } else {
                    h = mid - 1;
                }
            }
        }

        return nums[l];
    }
};
