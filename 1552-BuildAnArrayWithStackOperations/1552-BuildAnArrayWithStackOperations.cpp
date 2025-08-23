// Last updated: 8/23/2025, 2:37:02 PM
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        stack<int> st;
        vector<string> ans;
        int i=1;
        int j=0;
        while(i<=n){
            st.push(i);
            ans.push_back("Push");
            if(st.top()==target[j]){
                j++;
            }
            else{
                ans.push_back("Pop");
                st.pop();
            }
            if(st.size()==target.size()){
                break;
            }
            i++;
        }
        return ans;
    }
};