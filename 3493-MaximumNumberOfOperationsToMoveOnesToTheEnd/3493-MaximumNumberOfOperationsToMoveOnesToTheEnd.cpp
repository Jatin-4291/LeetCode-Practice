// Last updated: 8/30/2025, 1:22:31 PM
class Solution {
public:
    int maxOperations(string s) {
        int countOne=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                countOne++;
            }
            if(s[i]=='0'){
                ans+=countOne;
                while(s[i]=='0'){
                    i++;
                }
                countOne++;
            }
        }
        return ans;
    }
};