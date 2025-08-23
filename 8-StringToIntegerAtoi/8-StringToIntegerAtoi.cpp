// Last updated: 8/23/2025, 2:40:43 PM
class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        while (i < n && s[i] == ' ') i++; // skip whitespaces

        bool isNegative = false;
        if (i < n && s[i] == '-') {
            isNegative = true;
            i++;
        } else if (i < n && s[i] == '+') {
            i++;
        }

        long long num = 0;
        while (i < n && isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
            if (!isNegative && num > INT_MAX) return INT_MAX;
            if (isNegative && -num < INT_MIN) return INT_MIN;
            i++;
        }

        return isNegative ? -num : num;
    }
};
