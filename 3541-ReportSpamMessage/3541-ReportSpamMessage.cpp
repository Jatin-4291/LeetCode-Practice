// Last updated: 8/30/2025, 1:22:22 PM
class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_map<string,int> mp;
        for(int i=0;i<bannedWords.size();i++){
            mp[bannedWords[i]]++;
        }
        int count=0;
        for(int i=0;i<message.size();i++){

            if(mp[message[i]]){
                count++;
            }
        }
        if(count>=2){
            return true;
        }
        return false;
    }
};