// Last updated: 8/30/2025, 1:23:39 PM
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int count1 = count(s.begin(), s.end(), '1');
        int count0 = s.size() - count1;
        string result(count1 - 1, '1');
        result += string(count0, '0');
        result += '1';
        
        return result;
    }
};
