// Last updated: 8/23/2025, 2:37:07 PM
class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>x (26,-1);
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            x[s[i]-'a']=i;
            if(x[0]!=-1 && x[1]!=-1 && x[2]!=-1){
                ans+=(1+min({x[0],x[1],x[2]}));
            }
        }
        return ans;
    }
};