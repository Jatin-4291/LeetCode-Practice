// Last updated: 8/23/2025, 2:36:11 PM
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& basket) {
        vector<bool>used(basket.size());
        int count=0;
        for(int i=0;i<fruits.size();i++){
            for(int j=0;j<basket.size();j++){
                if(basket[j]>=fruits[i] && !used[j]){
                    used[j]=true;
                    count++;
                    break;
                }
            }
        }
        return fruits.size()-count;
    }
};