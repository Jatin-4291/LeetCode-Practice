// Last updated: 8/23/2025, 2:40:39 PM
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int mini = INT_MAX;
        for (int i = 0; i < strs.size(); i++) {
            mini = min(mini, (int)strs[i].size());
        }
        cout << mini;
        for(int i=0;i<mini;i++){
        char x=strs[0][i];
        for(int j=0;j<strs.size();j++){
            if(strs[j][i]!=x){
                return ans;
            }
        }
        ans+=x;
        }
        return ans;
    }

};