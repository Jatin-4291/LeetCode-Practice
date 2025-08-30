// Last updated: 8/30/2025, 1:22:45 PM
class Solution {
public:
    string clearDigits(string s) {
        string result;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
              
                if(!result.empty() && !isdigit(result.back())){
                    result.pop_back();
                }
            }
            else{
            result.push_back(s[i]);
            }
        }
        return result;
    }
};