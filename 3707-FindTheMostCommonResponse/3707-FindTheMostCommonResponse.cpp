// Last updated: 8/30/2025, 1:21:59 PM
class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        unordered_map<string, int> mp;
        
        for (int i = 0; i < responses.size(); i++) {
            unordered_map<string, bool> temp; 
            for (int j = 0; j < responses[i].size(); j++) {
                if (!temp[responses[i][j]]) {
                    mp[responses[i][j]]++;
                    temp[responses[i][j]] = true;
                }
            }
        }
        
        int ans = 0;
        string result = "";
        
        for (auto m : mp) {
            auto [key, val] = m;
            if (val > ans) {
                ans = val;
                result = key;
            } else if (val == ans) {
                if (key < result) {  
                    result = key;
                }
            }
        }
        
        return result;
    }
};
