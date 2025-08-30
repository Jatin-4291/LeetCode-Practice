// Last updated: 8/30/2025, 1:21:14 PM
class Solution {
public:
    string generateTag(string caption) {
        string tag = "#";
        bool firstWord = true;
        bool capitalize = false;

        for (int i = 0; i < caption.size(); ++i) {
            char c = caption[i];

            if (isalpha(c)) {
                if (firstWord) {
                    tag += tolower(c);   // always lowercase for the first letter of the first word
                    firstWord = false;
                } else if (capitalize) {
                    tag += toupper(c);   // Capitalize first letter of next word
                    capitalize = false;
                } else {
                    tag += tolower(c);   // lowercase rest of letters
                }
            } else if (c == ' ') {
                capitalize = !firstWord;  // start of a new word if not first
            }
            // ignore all other characters (digits, symbols, etc.)
        }

        if (tag.size() > 100) {
            tag = tag.substr(0, 100);
        }

        return tag;
    }
};
