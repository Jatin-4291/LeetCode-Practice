// Last updated: 8/23/2025, 2:40:46 PM
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int j=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            while(mp[s[i]]>0){
                mp[s[j]]--;
                j++;
            }
            mp[s[i]]++;
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};