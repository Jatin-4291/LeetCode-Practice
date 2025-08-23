// Last updated: 8/23/2025, 2:38:31 PM
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mp;
        for(char ch:s){
            mp[ch]++;
        }
        for(char ch:t){
            if(!mp[ch]){
                return false;
            }
            mp[ch]--;
            if(mp[ch]==0){
                mp.erase(ch);
            }
        }
        return mp.empty();
    }
};