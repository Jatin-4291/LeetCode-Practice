// Last updated: 8/23/2025, 2:35:37 PM
class Solution {
public:
    bool checkDivisibility(int n) {
        if (n == 0) return false;

        long long sum = 0;
        long long product = 1;
        int x = n;

        while (x > 0) {
            int digit = x % 10;
            sum += digit;
            product *= digit;
            x /= 10;
        }

        long long total = sum + product;
        cout << "Sum: " << sum << ", Product: " << product << ", Total: " << total << endl;

        return n % total == 0;
    }
};
