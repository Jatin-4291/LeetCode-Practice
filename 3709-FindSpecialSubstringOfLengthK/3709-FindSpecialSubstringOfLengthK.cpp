// Last updated: 8/30/2025, 1:21:58 PM
class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        if(s.size()==1){
            return true;
        }
        int i=0;
        for(int j=1;j<s.size();j++){
            if(s[j]!=s[j-1]){
                if((j-i)==k){
                    return true;
                }
                else{
                    i=j;
                }
            }
            if(j==s.size()-1){
                if(j-i+1==k){
                    return true;
                }
            }
        }
        return false;
    }
};