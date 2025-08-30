// Last updated: 8/30/2025, 1:21:57 PM
class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        // Helper function to calculate the transformation cost
        auto transformationCost = [](vector<int>& arr, vector<int>& brr) {
            long long cost = 0;
            for (int i = 0; i < arr.size(); i++) {
                cost += abs(arr[i] - brr[i]);
            }
            return cost;
        };

        // Calculate the cost without rearranging (original order)
        long long costWithoutRearrangement = transformationCost(arr, brr);

        // Sort both arrays and calculate the cost after sorting
        vector<int> sortedArr = arr;
        vector<int> sortedBrr = brr;
        sort(sortedArr.begin(), sortedArr.end());
        sort(sortedBrr.begin(), sortedBrr.end());
        long long costWithRearrangement = transformationCost(sortedArr, sortedBrr) + k;

        // Return the minimum of the two costs
        return min(costWithoutRearrangement, costWithRearrangement);
    }
};
