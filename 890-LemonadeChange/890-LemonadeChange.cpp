// Last updated: 8/23/2025, 2:37:35 PM
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives=0;
        int tens=0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                fives++;
            }
            if(bills[i]==10){
                tens++;
                if(fives>0){
                    fives--;
                }else{
                    return false;
                }
            }
            if(bills[i]==20){
                if(tens>0 && fives>0){
                    tens--;
                    fives--;
                }
                else if(fives>=3){
                    fives-=3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};