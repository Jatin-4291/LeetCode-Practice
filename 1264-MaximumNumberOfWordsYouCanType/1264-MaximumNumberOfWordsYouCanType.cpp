// Last updated: 9/21/2025, 8:48:31 PM
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int i = 0;
        int count = 0;

        while (i < text.size()) {
            bool found = false;

            while (i < text.size() && text[i] != ' ') {
                if (brokenLetters.find(text[i]) != string::npos) {
                    found = true;
                }
                i++;
            }

            if (!found) {
                count++;
            }

            i++;
        }

        return count;
    }
};
