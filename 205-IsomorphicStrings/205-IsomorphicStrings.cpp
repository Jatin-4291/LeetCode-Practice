// Last updated: 8/23/2025, 2:38:48 PM
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp;
        unordered_map<char,char> mp2;
        if(s.size()!=t.size()) return false;
        for(int i=0;i<s.size();i++){
            if(!mp[s[i]]){
                mp[s[i]]=t[i];
            }
            else{
                if(mp[s[i]]!=t[i]){
                    return false;
                }
            }
        }  
        for(int i=0;i<s.size();i++){
            if(!mp2[t[i]]){
                mp2[t[i]]=s[i];
            }
            else{
                if(mp2[t[i]]!=s[i]){
                    return false;
                }
            }
        }   
        return true;
    }
};