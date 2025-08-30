// Last updated: 8/30/2025, 1:23:05 PM
class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int zeroes=0;
        int ones=0;
        for(int i=0;i<possible.size();i++){
            if(possible[i]==0){
                zeroes++;
            }else{
                ones++;
            }
        }
        int count=0;
        int aliceScore=0;
        int bobScore=ones-zeroes;
        for(int i=0;i<possible.size()-1;i++){ 
            if(possible[i]==0){
                aliceScore--;
                bobScore++;
                
            }else{
                aliceScore++;
                bobScore--;
            }
            count++;
            if(aliceScore>bobScore){
                return count;
            }
        }
        return -1;
    }
};
