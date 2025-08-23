// Last updated: 8/23/2025, 2:40:32 PM
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='['|| s[i]=='{'){
            st.push(s[i]);
            }else{
                if(!st.empty()){
                if((s[i]==')' && st.top()=='(')||(s[i]==']' && st.top()=='[') || (s[i]=='}' && st.top()=='{')){
                st.pop();
                }
                else{
                    return false;
                }
                }
                else{
                    return false;
                }
            }
        }
        if(st.empty()) return true;
        return false;
    }
};