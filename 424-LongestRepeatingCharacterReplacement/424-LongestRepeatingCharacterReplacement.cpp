// Last updated: 8/23/2025, 2:38:08 PM
class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int r=0;
        int maxFreq=0;
        int ans=0;
        unordered_map<char,int> mp;
        int n=s.size();
        while(r<n){
            mp[s[r]]++;
            maxFreq=max(maxFreq,mp[s[r]]);
            if(((r-l+1)-maxFreq)>k){
                mp[s[l]]--;
                maxFreq=0;
                l++;
            }
            if((r-l+1)-maxFreq<=k){
                ans=max(ans,r-l+1);
            }
            r++;
        }
        return ans;
    }
};