// Last updated: 8/30/2025, 1:24:41 PM
class Solution {
public:
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    long long countVowels(string word) {
        int n = word.size();
        long long ans = 0;
        int count=0;
        for (int i = 0; i <n; i++) {
             if(isVowel(word[i])) {
                ans += (long long)(n - i) * (i + 1);
            }
        }

        return ans;
    }
};
