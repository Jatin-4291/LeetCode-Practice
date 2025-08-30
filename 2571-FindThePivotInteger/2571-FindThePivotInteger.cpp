// Last updated: 8/30/2025, 1:24:13 PM
class Solution {
public:
    int pivotInteger(int n) {
        int left = 0, right = 0;
        for (int i = 1; i <= n; i++) {
            right += i;
        }
        for (int i = 1; i <= n; i++) {
            right -= i;
            if (left == right) {
                return i;
            }
            left += i;
        }
        return -1;
    }
};
