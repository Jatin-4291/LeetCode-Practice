// Last updated: 8/23/2025, 2:36:50 PM
class Solution {
public:
    int beautySum(string s) {
        int n=s.length();
        int count=0;
        for(int i=0;i<n;i++){
            unordered_map<char,int> freq;
            for(int j=i;j<n;j++){
                freq[s[j]]++;
            int maxfreq=0,minfreq=INT_MAX;
            for(auto it:freq){
            maxfreq=max(maxfreq,it.second);
            minfreq=min(minfreq,it.second);
            }
            count+=(maxfreq-minfreq);
        }
        }
        return count;
    }
};