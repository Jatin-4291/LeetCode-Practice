// Last updated: 8/30/2025, 1:22:39 PM
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& arr) {
        int n = arr.size();
        int count = 0;

        for(int i = 0; i < n; i++) {
            int prev = (i - 1 >= 0) ? arr[i - 1] : arr[n - 1];
            int next = (i + 1 < n) ? arr[i + 1] : arr[0];

            if(prev != arr[i] && next != arr[i]) {
                count++;
            }
        }

        return count;
    }
};
