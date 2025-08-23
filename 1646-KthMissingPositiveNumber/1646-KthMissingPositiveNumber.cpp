// Last updated: 8/23/2025, 2:36:56 PM
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int missing_count = 0;
        int low = 0;
        int high = arr.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            missing_count = (arr[mid] - (mid + 1));
            if (missing_count < k) {
                low = mid + 1;
            } 
            else
                high = mid - 1;
        }
        return high + k + 1;
    }
};