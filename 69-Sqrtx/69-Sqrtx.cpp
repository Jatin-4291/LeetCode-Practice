// Last updated: 8/23/2025, 2:39:59 PM
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;

        int l = 0, h = x, ans = 0;
        while (l <= h) {
            long long mid = l + (h - l) / 2;  // safer than (l + h) / 2

            if (mid * mid == x) {
                return mid;
            }
            if (mid * mid < x) {
                ans = mid;     // mid is a candidate
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return ans;
    }
};
