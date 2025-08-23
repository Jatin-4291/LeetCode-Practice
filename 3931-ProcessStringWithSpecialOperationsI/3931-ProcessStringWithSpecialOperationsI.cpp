// Last updated: 8/23/2025, 2:35:31 PM
class Solution {
public:
    string processStr(string s) {
        string result = "";
        for (char c : s) {
            if (c == '*') {
                if (!result.empty())
                    result.pop_back();
            }
            else if (c == '%') {
                reverse(result.begin(), result.end());
            }
            else if (c == '#') {
                result += result;
            }
            else {
                result += c;
            }
        }
        return result;
    }
};
