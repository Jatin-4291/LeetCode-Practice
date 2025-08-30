// Last updated: 8/30/2025, 1:22:19 PM
class Solution {
public:
    bool isvowel(char c){
        if(c=='a' || c=='e' ||c=='i'|| c=='o' ||c=='u'){
            return true;
        }
        return false;
    }
    int solve2(string word,int k){
      int i=0;
        int j=0;
        int n=word.size();
        int c=0;
        int mx=0;
        unordered_map<char,int>mp;
        while(j<n){
             if(isvowel(word[j])==false){
                c++;
             }
             else{
                mp[word[j]]++;
             }
             while(mp.size()>=5 && c>k){
                if(isvowel(word[i])==true){
                    mp[word[i]]--;
                    if(mp[word[i]]==0){
                        mp.erase(word[i]);
                    }
                }
                else{
                    c--;
                }
                i++;
             }
             mx+=j-i+1;
             j++;

        }
        return mx;
    }
    int countOfSubstrings(string word, int k) {
        return solve2(word,k)-solve2(word,k-1);
    }
};