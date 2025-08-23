// Last updated: 8/23/2025, 2:40:01 PM
class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int bitA = (i >= 0) ? a[i] - '0' : 0;
            int bitB = (j >= 0) ? b[j] - '0' : 0;
            int sum = bitA ^ bitB ^ carry;
            carry = (bitA + bitB + carry) >= 2;

            ans = to_string(sum) + ans;
            i--;
            j--;
        }

        return ans;
    }
};
