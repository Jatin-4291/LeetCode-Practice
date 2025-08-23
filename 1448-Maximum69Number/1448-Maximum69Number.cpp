// Last updated: 8/23/2025, 2:37:09 PM
class Solution {
public:
    int maximum69Number (int num) {
        string x=to_string(num);
        for(int i=0;i<x.size();i++){
            if(x[i]-'0'==6){
                x[i]='9';
                break;
            }
        }
        return stoi(x);
    }
};