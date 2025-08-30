// Last updated: 8/30/2025, 1:23:14 PM
class Solution {
public:
    string lastNonEmptyString(string s) {
        map<char, vector<int>> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]].push_back(i);
        }

        int maxSize = 0;
        for (auto m : mp) {
            auto [ch, temp] = m;
            maxSize = max(maxSize, (int)temp.size());
        }

        vector<int> x;
        for (auto m : mp) {
            auto [ch, temp] = m;
            if ((int)temp.size() == maxSize) {
                x.push_back(temp[maxSize-1]);
            }
        }
        string ans;
        sort(x.begin(),x.end());
        for(int i=0;i<x.size();i++){
            ans+=s[x[i]];
        }

        return ans;
    }
};
