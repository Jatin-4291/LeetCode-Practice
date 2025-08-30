// Last updated: 8/30/2025, 1:23:23 PM
class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int i=0;
        int count=0;
        while(i<s1.size() || i<s2.size()||i<s3.size()){
            if(s1[i] == s2[i] && s2[i] == s3[i]){
                count++;
            }
            else{
                break;
            }
            i++;
        }
        if(count>0){
            return (s1.size()+s2.size()+s3.size()-3*count);
        }else{
            return -1;
        }

    }
};