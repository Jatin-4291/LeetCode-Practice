// Last updated: 8/30/2025, 1:25:04 PM
class Solution {
public:
    bool solve(int index, vector<int>& arr, int n, vector<bool>& used) {
        if (index == arr.size()) return true;  // Base case: all numbers placed

        if (arr[index] != 0) return solve(index + 1, arr, n, used); // Skip filled spots

        for (int i = n; i > 0; i--) { // Try placing from largest to smallest
            if (used[i]) continue;

            if (i == 1) {  // Special case: 1 appears only once
                arr[index] = 1;
                used[i] = true;

                if (solve(index + 1, arr, n, used)) return true;

                // Undo changes (backtrack)
                arr[index] = 0;
                used[i] = false;
            } else if (index + i < arr.size() && arr[index] == 0 && arr[index + i] == 0) {
                arr[index] = i;
                arr[index + i] = i;
                used[i] = true;

                if (solve(index + 1, arr, n, used)) return true;

                // Undo changes (backtrack)
                arr[index] = 0;
                arr[index + i] = 0;
                used[i] = false;
            }
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        vector<int> arr(n * 2 - 1, 0); 
        vector<bool> used(n + 1, false);
        solve(0, arr, n, used);
        return arr;
    }
};
