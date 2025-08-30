// Last updated: 8/30/2025, 1:24:54 PM
class Solution {
public:
    string removeOccurrences(string s, string part) {
        while (s.find(part) != std::string::npos) {
    s.erase(s.find(part), part.length());
}
return s;
    }

};