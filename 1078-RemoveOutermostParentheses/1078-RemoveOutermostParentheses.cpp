// Last updated: 8/23/2025, 2:37:17 PM
class Solution {
public:
    string removeOuterParentheses(string s) {
        int open=0;
       string ans="";
       for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            if(open>0) ans+=s[i];
            open++;
        }else{
            open--;
            if(open>0) ans+=s[i];
        }
       } 
       return ans;
    }
};