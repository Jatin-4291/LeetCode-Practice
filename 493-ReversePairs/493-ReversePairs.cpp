// Last updated: 8/23/2025, 2:38:00 PM
class Solution {
public:
    int count = 0;

    void merge(vector<int>& nums, int l, int mid, int h) {
        int j = mid + 1;
        for (int i = l; i <= mid; i++) {
            while (j <= h && nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }
        vector<int> temp;
        int i = l;
        j = mid + 1;

        while (i <= mid && j <= h) {
            if (nums[i] <= nums[j]) temp.push_back(nums[i++]);
            else temp.push_back(nums[j++]);
        }

        while (i <= mid) temp.push_back(nums[i++]);
        while (j <= h) temp.push_back(nums[j++]);

        for (int k = l; k <= h; k++) nums[k] = temp[k - l];
    }

    void mergeSort(vector<int>& nums, int l, int h) {
        if (l >= h) return;
        int mid = (l + h) / 2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, h);
        merge(nums, l, mid, h);
    }

    int reversePairs(vector<int>& nums) {
        count = 0;
        mergeSort(nums, 0, nums.size() - 1);
        return count;
    }
};
