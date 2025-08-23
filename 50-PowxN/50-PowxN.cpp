// Last updated: 8/23/2025, 2:40:14 PM
class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        double result = 1.0;
        while (N > 0) {
            if (N & 1) {
                result *= x;
            }
            x *= x;
            N >>= 1;
        }

        return result;
    }
};
