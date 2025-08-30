// Last updated: 8/30/2025, 1:23:24 PM
class Solution {
public:
    long long minimumSteps(string s) {
        long long black=0;
        long long barrierWhite=0;
        long long tempBlack=0;
        long long ans=0;
        int i=0;
        while(i<s.size()){
            if(s[i]=='1'){
                tempBlack++;
            }
            if(s[i]=='0' && tempBlack!=0){
                black+=tempBlack;
                while(s[i]=='0'){
                    barrierWhite++;
                    i++;
                }
                ans+=(black*barrierWhite);
                tempBlack=1;
                barrierWhite=0;
            }
            i++;
        }
        return ans;
    }
};