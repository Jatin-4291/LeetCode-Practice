// Last updated: 8/23/2025, 2:35:41 PM
class Solution {
public:
    vector<string> partitionString(string s) {
        unordered_set<string> seen;
        vector<string> segments;

        int i = 0;
        int n = s.size();
        string x="";
        for(int i=0;i<s.size();i++){
            x+=s[i];
            if(!seen.count(x)){
                segments.push_back(x);
                seen.insert(x);
                x="";
            }
        }
        return segments;
    }
};
