// Last updated: 8/23/2025, 2:39:24 PM
class Solution {
public:
    bool isPalindrome(int i,int j,string s){
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void solve(int i,string s,vector<string>& temp,vector<vector<string>>& ans){
        if(i>=s.size()){
            ans.push_back(temp);
            return;
        }
        for(int j=i;j<s.size();j++){
            if(isPalindrome(i,j,s)){
                string x=s.substr(i,j-i+1);
                temp.push_back(x);
                solve(j+1,s,temp,ans);
                temp.pop_back();
            }
        }
        

    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> ans;
        solve(0,s,temp,ans);
        return ans;
    }
};