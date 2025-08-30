// Last updated: 8/30/2025, 1:24:34 PM
class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n =matrix.size();
         for(int i = 0; i < n; i++) {
            unordered_map<char, int> mp;
            for(int j = 0; j < n; j++) {
                mp[matrix[i][j]]++;
            }
            if(mp.size()!=n){
                return false;
            }
        }
        for(int j = 0; j < n; j++) {
            unordered_map<char, int> mp;
            for(int i = 0; i < n; i++) {
                mp[matrix[i][j]]++;
            }
            if(mp.size()!=n){
                return false;
            }
        }
        return true;
    }
};