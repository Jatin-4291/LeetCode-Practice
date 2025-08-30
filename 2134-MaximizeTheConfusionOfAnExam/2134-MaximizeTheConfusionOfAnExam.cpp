// Last updated: 8/30/2025, 1:24:45 PM
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(maxConsecutiveChar(answerKey, k, 'T'), maxConsecutiveChar(answerKey, k, 'F'));
    }

private:
    int maxConsecutiveChar(const string& s, int k, char ch) {
        int maxLen = 0, left = 0, flips = 0;
        for (int right = 0; right < s.size(); ++right) {
            if (s[right] != ch) {
                flips++;
            }
            while (flips > k) {
                if (s[left] != ch) {
                    flips--;
                }
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
