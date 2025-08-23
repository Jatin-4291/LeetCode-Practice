// Last updated: 8/23/2025, 2:36:36 PM
class Solution {
public:
    string largestGoodInteger(string num) {
        unordered_map<int,int> mp;
        int j=0;
        int ans=-1;
        for(int i=0;i<num.size();i++){
            mp[num[i]-'0']++;
            if(i-j+1>3){
                mp[num[j]-'0']--;
                if(mp[num[j]-'0']==0){
                    mp.erase(num[j]-'0');
                }
                j++;
            }
            if(i-j+1==3 && mp.size()==1){
                ans=max(ans,mp.begin()->first);
            }
        }
        if (ans == -1) return "";
        string res="";
        for(int i=0;i<3;i++){
            res+=to_string(ans);
        }
        return res;
    }
};