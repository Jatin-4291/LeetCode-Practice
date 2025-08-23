// Last updated: 8/23/2025, 2:36:48 PM
class Solution {
public:
    string largestOddNumber(string num) {
        int farthestOdd = -1;
        for (int i = num.size() - 1; i >= 0; i--) {
            if ((num[i] - '0') % 2 != 0) {
                farthestOdd = i;
                break;
            }
        }
        if (farthestOdd == -1) return "";
        return num.substr(0, farthestOdd + 1);
    }
};
