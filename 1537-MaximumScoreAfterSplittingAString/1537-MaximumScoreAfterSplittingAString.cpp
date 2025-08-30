// Last updated: 8/30/2025, 1:25:22 PM
class Solution {
public:
    int maxScore(string s) {
     int left=0;
     int right =0;
     int ans=0;
     for(int i=0;i<s.size();i++){
        right+=s[i]-'0';
     }   
     for(int i=0;i<s.size()-1;i++){
        if(s[i]-'0'==0){
            left++;
        }
        if(s[i]-'0'==1){
            right--;
        }
        ans=max(ans,(left+right));
     }
     return ans;
    }
};