// Last updated: 8/30/2025, 1:25:21 PM
class Solution {
public:
    bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}
    int maxVowels(string s, int k) {
        int i=0;
        int j=0;
        int count=0;
        int ans=0;
        while(j<s.size()){
            if(isVowel(s[j])){
                count++;
            }
            if(j-i+1==k){
                if(count>ans){
                    ans=count;
                }
                 if (isVowel(s[i])) {
                    count--;
                }
                i++;
            }
           
            j++;
        }
        return ans;
    }
};