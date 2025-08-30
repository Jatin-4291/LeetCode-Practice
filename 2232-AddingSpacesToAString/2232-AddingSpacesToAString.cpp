// Last updated: 8/30/2025, 1:24:37 PM
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans;
        int space=0;
        for(int i=0;i<s.size();i++){
        if (space < spaces.size() && spaces[space] == i){
                ans+=" ";
                ans+=s[i];
                space++;
            }
            else{
                ans+=s[i];
            }
        }
        return ans;
    }
};