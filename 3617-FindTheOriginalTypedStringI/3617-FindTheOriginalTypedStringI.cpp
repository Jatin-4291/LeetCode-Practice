// Last updated: 8/23/2025, 2:36:21 PM
class Solution {
public:
    int possibleStringCount(string word) {
    int ans = 0;
    int i = 0;
    while (i < word.size()) {
        int j = i;
        while (j < word.size() && word[j] == word[i]) {
            j++;
        }
        int count = j - i;
        if (count > 1) {
            ans += count - 1;
        }
        i = j;
    }
    return ans + 1;
}
};