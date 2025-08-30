// Last updated: 8/30/2025, 1:23:41 PM
class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i=0;
        int j=0;
        while(i<str1.size() && j<str2.size()){
            if(str1[i]==str2[j]){
                i++;
                j++;
            }
            else{
                if(str1[i]!='z'){

                if(str1[i] + 1==str2[j]){
                    i++;
                    j++;
                }
                else{
                    i++;
                }
                }
                else{
                   if(str2[j]=='a'){
                    i++;
                    j++;
                } 
                else{
                    i++;
                }
                }

                
            }
        }
        if(j==str2.size()){
            return true;
        }
        else{
            return false;
        }
    }
};