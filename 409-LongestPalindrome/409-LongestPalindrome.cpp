// Last updated: 8/23/2025, 2:38:11 PM
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        int sum=0;
        for(auto [key,val]:mp){
        if(val%2==0){
            sum+=val;
        }
        else{
            sum+=(val-1);
        }
        }
        if(sum==s.size()) return sum;
        return sum+1;
    }
};