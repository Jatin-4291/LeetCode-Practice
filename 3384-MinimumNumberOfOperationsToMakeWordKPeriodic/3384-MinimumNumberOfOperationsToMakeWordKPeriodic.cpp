// Last updated: 8/30/2025, 1:22:58 PM
class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string,int> mp;
        int i=0;
        while(i<word.size()){
            mp[word.substr(i,k)]++;
            i+=k;
        }
        int maxi=0;
        int sum=0;
        for(auto m:mp){
            auto[key,val]=m;
            sum+=val;
            maxi=max(maxi,val);
        }
        return sum-maxi;
        
        
    }
};