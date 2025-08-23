// Last updated: 8/23/2025, 2:35:40 PM
class Solution {
public:
    string concatHex36(int n) {
        int x = n * n;
        string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string hex = "";
        while (x > 0) {
            int rem = x % 16;
            if (rem < 10) hex = char('0' + rem) + hex;
            else hex = char('A' + rem - 10) + hex;
            x /= 16;
        }
        int y = n * n * n;
        string hex2 = "";
        while (y > 0) {
            hex2 = digits[y % 36] + hex2;
            y /= 36;
        }

        return hex + hex2;
    }
};
