// Last updated: 8/23/2025, 2:40:23 PM
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = -1;
        int l = 0, h = nums.size() - 1;
        while (l <= h) {
            int mid = (l + h) / 2;
            if (nums[mid] == target) {
                if (mid == 0 || nums[mid - 1] != target) {
                    start = mid;
                    break;
                } else {
                    h = mid - 1;
                }
            } else if (nums[mid] > target) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        int end = -1;
        l = 0, h = nums.size() - 1;
        while (l <= h) {
            int mid = (l + h) / 2;
            if (nums[mid] == target) {
                if (mid == nums.size() - 1 || nums[mid + 1] != target) {
                    end = mid;
                    break;
                } else {
                    l = mid + 1;
                }
            } else if (nums[mid] > target) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return {start, end};
    }
};
