// Last updated: 8/23/2025, 2:38:06 PM
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(char ch:s){
            mp[ch]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto [key,val]:mp){
            pair<int,char> x={val,key};
            pq.push(x);
        }
        string ans="";
        while(!pq.empty()){
            auto [cnt,ch]=pq.top();
            pq.pop();
            for(int i=0;i<cnt;i++){
            ans+=ch;
            }
        }
        return ans;
    }
};