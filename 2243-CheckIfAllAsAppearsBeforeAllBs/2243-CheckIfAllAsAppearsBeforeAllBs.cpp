// Last updated: 8/30/2025, 1:24:36 PM
class Solution {
public:
    bool checkString(string s) {
    vector<int> arr(s.size(), 0);
    int bIndex;
    for(int i=0;i<s.size();i++){
        if(s[i]=='b'){
            bIndex=i;
            break;
        }
    }
    for(int i=bIndex;i<s.size();i++){
        if(s[i]=='a'){
            return false;
        }
    }
    return true;
    }
};