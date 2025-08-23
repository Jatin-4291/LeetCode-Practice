// Last updated: 8/23/2025, 2:39:00 PM
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int sum = 0;
        long long power = 1;
        for (int j = columnTitle.size() - 1; j >= 0; j--) {
            sum += power * (columnTitle[j] - 'A' + 1);
            power *= 26;
        }
        return sum;
    }
};
