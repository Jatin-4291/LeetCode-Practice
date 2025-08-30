// Last updated: 8/30/2025, 1:22:44 PM
class Solution {
public:
    string compressedString(string word) {
        string ans = "";
        int count = 1;  

        for (int i = 1; i <= word.size(); i++) {
            if (i < word.size() && word[i] == word[i - 1]) {
                count++;  
            } else {
                while (count > 9) {
                    ans += "9" + string(1, word[i - 1]);
                    count -= 9;
                }
                ans += to_string(count) + word[i - 1]; 
                count = 1;
            }
        }
        return ans;
    }
};
