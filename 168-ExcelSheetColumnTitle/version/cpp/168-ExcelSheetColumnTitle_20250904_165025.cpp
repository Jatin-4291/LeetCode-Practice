// Last updated: 9/4/2025, 4:50:25 PM
class Solution {
public:
    string convertToTitle(int n) {
        string ans="";
        while(n>0){
            n--;
            ans=char('A'+(n%26))+ans;
            n=n/26;
        }
        return ans;
    }
};