// Last updated: 8/30/2025, 1:24:46 PM
class Solution {
public:
    string reversePrefix(string word, char ch) {
        stack<int> st;
        bool flag=false;
        for(int i=0;i<word.size();i++){
            if(word[i]!=ch){
                st.push(word[i]);
            }
            else{
                flag=true;
                st.push(word[i]);
                break;
            }
        }
        if (flag) {
            for (int i = 0; !st.empty(); i++) {
                word[i] = st.top();
                st.pop();
            }
        }
        return word;
    }
};