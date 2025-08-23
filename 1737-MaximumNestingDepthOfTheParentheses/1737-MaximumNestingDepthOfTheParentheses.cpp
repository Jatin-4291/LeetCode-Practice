// Last updated: 8/23/2025, 2:36:54 PM
class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int ans=0;
        for(char ch: s){
            ans=max(ans,(int)st.size());
            if(ch=='('){
                st.push('(');
            } 
            if(ch==')'){
                if(!st.empty()){
                    st.pop();
                }
            }
        }
        return ans;
    }
};