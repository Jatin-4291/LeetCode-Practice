// Last updated: 8/23/2025, 2:36:24 PM
class Solution {
public:
    char NextAlpha(char character)
    {
    if (character == 'Z') return 'A';
    else if (character == 'z') return 'a';

    return character + 1;
    }
    char kthCharacter(int k) {
        string str="a";
        while(str.size()<k){
        int n = str.size();
        for(int i=0;i<n;i++){
            str.push_back(NextAlpha(str[i]));
        }
        }
        return str[k-1];
        
    }
};